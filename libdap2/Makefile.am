## This is a automake file, part of Unidata's netCDF package.
# Copyright 2018, see the COPYRIGHT file for more information.

# This automake file generates the Makefile to libdap2. Whatever that
# is!

# Put together AM_CPPFLAGS and AM_LDFLAGS.
include $(top_srcdir)/lib_flags.am

# We may have to add to these later.
DISTCLEANFILES =
MAINTAINERCLEANFILES =
CLEANFILES =
EXTRA_DIST = CMakeLists.txt

LDADD=

SRC= constraints.c dapcvt.c dapodom.c daputil.c	\
ncdaperr.c cdf.c cache.c dapdump.c dapdebug.c dapattr.c		\
ncd2dispatch.c getvara.c dceconstraints.c dcetab.c		\
dceparse.c dcelex.c

HDRS= nccommon.h constraints.h ncd2dispatch.h dapincludes.h 	\
dapodom.h getvara.h dapnc.h daputil.h dapdebug.h dapdump.h		\
dceconstraints.h dcetab.h dceparselex.h

if NETCDF_ENABLE_DAP

if USE_NETCDF4
AM_CPPFLAGS += -I$(top_srcdir)/libsrc4
endif

# Build convenience library
noinst_LTLIBRARIES = libdap2.la
libdap2_la_SOURCES = $(SRC) $(HDRS)
libdap2_la_CPPFLAGS = $(AM_CPPFLAGS)
libdap2_la_LIBADD =

#if USE_NETCDF4
#LDADD += ${top_builddir}/libsrc4/libnetcdf4.la
#endif
#
#LDADD += ${top_builddir}/libsrc/libnetcdf3.la		\
#	 ${top_builddir}/oc2/liboc.la			\
#	 ${top_builddir}/libdispatch/libdispatch.la
#
endif # NETCDF_ENABLE_DAP

# These rule are used if someone wants to rebuild the grammar files.
# Otherwise never invoked, but records how to do it.
# BTW: note that renaming is essential because otherwise
# autoconf will forcibly delete files of the name *.tab.*

EXTRA_DIST += dce.y

makece::
	bison -v -d -t -p dce dce.y
	rm -f dcetab.c dcetab.h
	sed -e 's/dce[.]tab[.]c/dcetab.c/g' -e 's/dce[.]tab[.]h/dcetab.h/g' <dce.tab.c >dcetab.c
	sed -e 's/dce[.]tab[.]c/dcetab.c/g' -e 's/dce[.]tab[.]h/dcetab.h/g' <dce.tab.h >dcetab.h
