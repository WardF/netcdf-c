/*! \file

Copyright 1993-2025
University Corporation for Atmospheric Research/Unidata.

See \ref copyright file for more info.

*/
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nctestserver.h"

#define PINGTIME 25

/* Attempt to shut up LGTM */
#define HTTP "http"
#define HTTPS "https"

/**
usage: pingurl <svc>
See if a specific server at a given url appears to be up.
*/

static void
usage()
{
    fprintf(stderr,"usage: pingurl <svc>\n");
    exit(1);
}


int
main(int argc, char** argv)
{
    char url[MAXSERVERURL+1];
    int found = 0;
    int ishttps = 0;

    argc--; argv++;
    if(argc < 1)
	usage();
 
    /* Try http: first */
    snprintf(url,MAXSERVERURL,HTTP"://%s",argv[0]);
    if(timedping(url,PINGTIME) == NC_NOERR) 
	found = 1;
    else {
	/* Try https: next */
        snprintf(url,MAXSERVERURL,HTTPS"://%s",argv[0]);
	if(timedping(url,PINGTIME) == NC_NOERR) {
	    found = 1;
	    ishttps = 1;
	}
    }    
    if(found)
        printf((ishttps?"https\n":"http\n"));
    else
        printf("no\n");
    exit(0);
}
