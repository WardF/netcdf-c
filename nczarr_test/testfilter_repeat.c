/*
  Copyright 2018, UCAR/Unidata
  See COPYRIGHT file for copying and redistribution conditions.
*/

#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>

#include "netcdf.h"
#include "netcdf_filter.h"

#undef TESTODDSIZE

#undef DEBUG

#define FILTER_ID 40000

#define MAXERRS 8

#define MAXPARAMS 32

#define MAXDIMS 8

#define DFALT_TESTFILE "testfilter_reg.nc"

#define NPARAMS 1
#define PARAMVAL 17

#define NDIMS 4
static size_t dimsize[NDIMS] = {4,4,4,4};
static size_t chunksize[NDIMS] = {4,4,4,4};

static int ndims = NDIMS;

static size_t totalproduct = 1; /* x-product over max dims */
static size_t actualproduct = 1; /* x-product over actualdims */
static size_t chunkproduct = 1; /* x-product over actual chunks */

static int nerrs = 0;

static char* testfile = NULL;


static int ncid, varid;
static int dimids[MAXDIMS];
static size_t odom[MAXDIMS];
static float* array = NULL;
static float* expected = NULL;

/* Forward */
static int filter_test1(void);
static void init(int argc, char** argv);
static void reset(void);
static void odom_reset(void);
static int odom_more(void);
static int odom_next(void);
static int odom_offset(void);
static float expectedvalue(void);

#define ERRR do { \
fflush(stdout); /* Make sure our stdout is synced with stderr. */ \
fprintf(stderr, "Sorry! Unexpected result, %s, line: %d\n", \
        __FILE__, __LINE__);                                \
nerrs++;\
} while (0)

static int
check(int err,int line)
{
    if(err != NC_NOERR) {
        fprintf(stderr,"fail (%d): %s\n",line,nc_strerror(err));
    }
    return NC_NOERR;
}

static void
report(const char* msg, int lineno)
{
    fprintf(stderr,"fail: line=%d %s\n",lineno,msg);
    exit(1);
}

#define CHECK(x) check(x,__LINE__)
#define REPORT(x) report(x,__LINE__)

static int
verifychunks(void)
{
    int i;
    int store = -1;
    size_t localchunks[MAXDIMS];
    memset(localchunks,0,sizeof(localchunks));
    CHECK(nc_inq_var_chunking(ncid, varid, &store, localchunks));
    if(store != NC_CHUNKED) {
        fprintf(stderr,"bad chunk store\n");
        return 0;
    }
    for(i=0;i<ndims;i++) {
        if(chunksize[i] != localchunks[i]) {
            fprintf(stderr,"bad chunk size: %d\n",i);
            return 0;
        }
    }
    return 1;
}

static int
create(void)
{
    int i;

    /* Create a file with one big variable */
    CHECK(nc_create(testfile, NC_NETCDF4|NC_CLOBBER, &ncid));
    CHECK(nc_set_fill(ncid, NC_NOFILL, NULL));
    for(i=0;i<ndims;i++) {
        char dimname[1024];
        snprintf(dimname,sizeof(dimname),"dim%d",i);
        CHECK(nc_def_dim(ncid, dimname, dimsize[i], &dimids[i]));
    }
    CHECK(nc_def_var(ncid, "var", NC_FLOAT, ndims, dimids, &varid));
    return NC_NOERR;
}

static void
deffilter(unsigned int id, size_t nparams, unsigned int* params)
{
    /* Register filter */
    CHECK(nc_def_var_filter(ncid,varid,id,nparams,params));
}

static void
printfilter(unsigned int id)
{
    size_t i,nparams = 0;
    unsigned int params[MAXPARAMS];

    CHECK(nc_inq_var_filter_info(ncid,varid,id,&nparams,params));;
    if(nparams == 0) REPORT("no nparams");
    printf("filter(%u): |params|=%u params=",id,(unsigned)nparams);
    for(i=0;i<nparams;i++)
	printf(" %u",params[i]);
    printf("\n");
}

static int
openfile(void)
{
    unsigned int filterids[MAXPARAMS];
    size_t nfilters = 0;
    int k;

    /* Open the file and check it. */
    CHECK(nc_open(testfile, NC_NOWRITE, &ncid));
    CHECK(nc_inq_varid(ncid, "var", &varid));

    /* Verify chunking */
    if(!verifychunks())
        return 0;
    /* Check the compression algorithms */
    CHECK(nc_inq_var_filter_ids(ncid,varid,&nfilters,filterids));
    for(k=0;k<nfilters;k++)
	printfilter(filterids[k]);
    fflush(stderr);
    return 1;
}

static int
setchunking(void)
{
    int store;

    store = NC_CHUNKED;
    CHECK(nc_def_var_chunking(ncid,varid,store,chunksize));
    if(!verifychunks())
        return NC_EINVAL;
    return NC_NOERR;
}

static void
fill(void)
{
   odom_reset();
   if(1) {
        int i;
        if(actualproduct <= 1) abort();
        for(i=0;i<actualproduct;i++)
            expected[i] = (float)i;
   } else {
       while(odom_more()) {
            int offset = odom_offset();
            float expect = expectedvalue();
            expected[offset] = expect;
            odom_next();
        }
   }
}

static int
compare(void)
{
    int errs = 0;
    printf("data comparison: |array|=%ld\n",(unsigned long)actualproduct);
    if(1)
    {
        int i;
        for(i=0;i<actualproduct;i++) {
            if(expected[i] != array[i]) {
                fprintf(stderr,"data mismatch: array[%d]=%f expected[%d]=%f\n",
                            i,array[i],i,expected[i]);
                errs++;
                if(errs >= MAXERRS)
                    break;
            }
        }
   } else
   {
       odom_reset();
       while(odom_more()) {
            int offset = odom_offset();
            float expect = expectedvalue();
            if(array[offset] != expect) {
                fprintf(stderr,"data mismatch: array[%d]=%f expected=%f\n",
                            offset,array[offset],expect);
                errs++;
                if(errs >= MAXERRS)
                    break;
            }
            odom_next();
       }
   }

   if(errs == 0)
        printf("no data errors\n");
   return (errs == 0);
}

static int
filter_test1(void)
{
    int ok = 1;
    unsigned int params[MAXPARAMS];    

    reset();

    printf("test1: def filter repeat .\n");
    create();
    setchunking();

    params[0] = 1;
    params[1] = 17;
    deffilter(FILTER_ID,2,params);

    params[0] = 0;
    params[1] = 18;
    deffilter(FILTER_ID,2,params);

    CHECK(nc_enddef(ncid));

    /* Fill in the array */
    fill();

    printf("test1: compression.\n");
    /* write array */
    CHECK(nc_put_var(ncid,varid,expected));
    CHECK(nc_close(ncid));

    printf("test1: decompression.\n");
    reset();
    openfile();
    CHECK(nc_get_var_float(ncid, varid, array));
    ok = compare();

    CHECK(nc_close(ncid));
    return ok;
}

/**************************************************/
/* Utilities */

static void
reset()
{
    memset(array,0,sizeof(float)*actualproduct);
}

static void
odom_reset(void)
{
    memset(odom,0,sizeof(odom));
}

static int
odom_more(void)
{
    return (odom[0] < dimsize[0]);
}

static int
odom_next(void)
{
    int i; /* do not make unsigned */
    for(i=ndims-1;i>=0;i--) {
        odom[i] += 1;
        if(odom[i] < dimsize[i]) break;
        if(i == 0) return 0; /* leave the 0th entry if it overflows*/
        odom[i] = 0; /* reset this position*/
    }
    return 1;
}

static int
odom_offset(void)
{
    int i;
    int offset = 0;
    for(i=0;i<ndims;i++) {
        offset *= (int)dimsize[i];
        offset += (int)odom[i];
    }
    return offset;
}

static float
expectedvalue(void)
{
    int i;
    float offset = 0;

    for(i=0;i<ndims;i++) {
        offset *= (float)dimsize[i];
        offset += (float)odom[i];
    }
    return offset;
}

static void
init(int argc, char** argv)
{
    int i;

    /* get the testfile path */
    if(argc > 1)
        testfile = argv[1];
    else
        testfile = DFALT_TESTFILE;

    /* Setup various variables */
    totalproduct = 1;
    actualproduct = 1;
    chunkproduct = 1;
    for(i=0;i<NDIMS;i++) {
	totalproduct *= dimsize[i];
        if(i < ndims) {
            actualproduct *= dimsize[i];
            chunkproduct *= chunksize[i];
        }
    }
    /* Allocate max size */
    array = (float*)calloc(1,sizeof(float)*actualproduct);
    expected = (float*)calloc(1,sizeof(float)*actualproduct);
}

/**************************************************/
int
main(int argc, char **argv)
{
#ifdef DEBUG
    H5Eprint1(stderr);
    nc_set_log_level(1);
#endif
    init(argc,argv);
    if(!filter_test1()) ERRR;
    exit(nerrs > 0?1:0);
}
