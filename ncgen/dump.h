/*! \file

Copyright 1993-2025
University Corporation for Atmospheric Research/Unidata.

See \ref copyright file for more info.

*/

#ifndef NCGEN_DUMP_H
#define NCGEN_DUMP_H

/*#define F*/

/*********************************************************************
 *   Copyright 2026, UCAR/Unidata
 *   See netcdf/COPYRIGHT file for copying and redistribution conditions.
 *   $Header: /upc/share/CVS/netcdf-3/ncgen/dump.h,v 1.2 2010/04/04 19:39:44 dmh Exp $
 *********************************************************************/

extern void dumptransform(Datalist*);
extern void dumpdatalist(Datalist*,char*);
extern void dumpconstant(NCConstant*,char*);
extern void bufdump(Datalist*,Bytebuffer*);
extern void dumpgroup(Symbol* g);

#endif
