/*! \file

Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014,
2015, 2016, 2017, 2018
University Corporation for Atmospheric Research/Unidata.

See \ref copyright file for more info.

*/

/* This program adds two new variables to an existing netCDF file.
 * It is used to test if netCDF can correctly calculate the file offsets
 * for the two new variables, in particular for files that align the
 * fix-size variables to a boundary larger than 4 bytes, for instance
 * a file created by PnetCDF with default alignment of 512 bytes.
 *
 * This program should run after tst_pnetcdf.c and takes the output file
 * from tst_pnetcdf.c as input on the command-line.
 *
 * To check the file offsets for all variables, adding a printf statement is
 * necessary in netcdf-4.3.3.1/libsrc/nc3internal.c around line 222,
 * for example,
 * printf("var %s: begin=%ld len=%ld end=%ld\n",(*vpp)->name->cp, (*vpp)->begin, (*vpp)->len, (*vpp)->begin+(*vpp)->len);
 *
 * Check the first new variable's begin to see whether it is less than
 * the last variable's offset in the existing file.
 */
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <netcdf.h>

#define ERR {if(err!=NC_NOERR){printf("Error at line=%d: %s\n", __LINE__, nc_strerror(err));nerrs++;}}

int main(int argc, char** argv) {
    int i, j, err, nerrs=0, ncid, varid[5], dimid[2];
    int old_buf[3][5], get_buf[3][5], new_buf[1024];
    char *filename;

    filename = argv[1];
    if (argc == 1) filename = "tst_pnetcdf.nc";

    err = nc_open(filename, NC_WRITE, &ncid); ERR
    if (err != NC_NOERR) return 1;

    /* read all fixed-size variables */
    err = nc_inq_varid(ncid, "fixed_var_1", &varid[0]);
    err = nc_inq_varid(ncid, "fixed_var_3", &varid[1]);
    err = nc_inq_varid(ncid, "fixed_var_5", &varid[2]);
    err = nc_get_var_int(ncid, varid[0], old_buf[0]); ERR
    err = nc_get_var_int(ncid, varid[1], old_buf[1]); ERR
    err = nc_get_var_int(ncid, varid[2], old_buf[2]); ERR

    err = nc_redef(ncid); ERR

    /* add 2 new dimensions */
    err = nc_def_dim(ncid, "new_dim_1", 32, &dimid[0]); ERR
    err = nc_def_dim(ncid, "new_dim_2", 32, &dimid[1]); ERR

    /* add 2 new dimensions */
    err = nc_def_var(ncid, "new_var1", NC_INT,   2, dimid, &varid[3]); ERR
    err = nc_def_var(ncid, "new_var2", NC_FLOAT, 2, dimid, &varid[4]); ERR
    err = nc_enddef(ncid); ERR

    /* write more than 512 bytes (the default alignment used in PnetCDF) */
    for (i=0; i<1024; i++) new_buf[i] = -1;
    err = nc_put_var_int(ncid, varid[3], new_buf); ERR

    /* read and check all variables from the original file */
    err = nc_get_var_int(ncid, varid[0], get_buf[0]); ERR
    err = nc_get_var_int(ncid, varid[1], get_buf[1]); ERR
    err = nc_get_var_int(ncid, varid[2], get_buf[2]); ERR

    for (i=0; i<3; i++) {
        char varname[32];
        snprintf(varname, sizeof(varname), "fixed_var_%d",2*i+1);
        for (j=0; j<5; j++) {
            if (get_buf[i][j] != old_buf[i][j]) {
                printf("Error in %s line %d: expecting %s[%d]=%d but got %d\n",
                       __FILE__,__LINE__,varname,j,old_buf[i][j],get_buf[i][j]);
                nerrs++;
            }
        }
    }

    err = nc_close(ncid); ERR

/*
    SUMMARIZE_ERR;
    FINAL_RESULTS;
*/
    return (nerrs > 0);
}
