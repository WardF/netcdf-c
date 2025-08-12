/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* default file chunk cache nelems. */
#define CHUNK_CACHE_NELEMS DEFAULT_CHUNKS_IN_CACHE

/* default file chunk cache preemption policy. */
#define CHUNK_CACHE_PREEMPTION DEFAULT_CHUNK_CACHE_PREEMPTION

/* default file chunk cache size in bytes. */
#define CHUNK_CACHE_SIZE DEFAULT_CHUNK_CACHE_SIZE

/* Define to 1 if using 'alloca.c'. */
/* #undef C_ALLOCA */

/* default max num chunks in chunk cache. */
#define DEFAULT_CHUNKS_IN_CACHE 1000

/* default file chunk cache preemption policy. */
#define DEFAULT_CHUNK_CACHE_PREEMPTION 0.75

/* default size of the chunk cache. */
#define DEFAULT_CHUNK_CACHE_SIZE 67108864U

/* default chunk size in bytes */
#define DEFAULT_CHUNK_SIZE 4194304

/* If true, enable filter installation */
/* #undef ENABLE_PLUGIN_DIR */

/* if true, use _FillValue for NC_ERANGE data elements */
/* #undef ERANGE_FILL */

/* use HDF5 1.6 API */
#define H5_USE_16_API 1

/* Define to 1 if you have 'alloca', as a function or macro. */
#define HAVE_ALLOCA 1

/* Define to 1 if <alloca.h> works. */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the `atexit' function. */
#define HAVE_ATEXIT 1

/* if true, blosc library is available */
/* #undef HAVE_BLOSC */

/* if true, bzip2 library is installed */
/* #undef HAVE_BZ2 */

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H 1

/* Is CURLINFO_RESPONSE_CODE defined */
#define HAVE_CURLINFO_RESPONSE_CODE 1

/* Is CURLOPT_BUFFERSIZE defined */
#define HAVE_CURLOPT_BUFFERSIZE 1

/* Is CURLOPT_TCP_KEEPALIVE defined */
#define HAVE_CURLOPT_KEEPALIVE 1

/* Is CURLOPT_KEYPASSWD defined */
#define HAVE_CURLOPT_KEYPASSWD 1

/* Is CURLOPT_PASSWORD defined */
#define HAVE_CURLOPT_PASSWORD 1

/* Is CURLOPT_USERNAME defined */
#define HAVE_CURLOPT_USERNAME 1

/* Define to 1 if you have the declaration of `isfinite', and to 0 if you
   don't. */
#define HAVE_DECL_ISFINITE 1

/* Define to 1 if you have the declaration of `isinf', and to 0 if you don't.
   */
#define HAVE_DECL_ISINF 1

/* Define to 1 if you have the declaration of `isnan', and to 0 if you don't.
   */
#define HAVE_DECL_ISNAN 1

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fileno' function. */
#define HAVE_FILENO 1

/* Define to 1 if you have the `fsync' function. */
#define HAVE_FSYNC 1

/* Define to 1 if you have the <ftw.h> header file. */
#define HAVE_FTW_H 1

/* getfattr is available */
/* #undef HAVE_GETFATTR */

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the `getrlimit' function. */
#define HAVE_GETRLIMIT 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the `H5Literate' function. */
#define HAVE_H5LITERATE 1

/* Define to 1 if you have the `H5Literate2' function. */
/* #undef HAVE_H5LITERATE2 */

/* Define to 1 if you have the `H5Pget_fapl_mpio' function. */
/* #undef HAVE_H5PGET_FAPL_MPIO */

/* Define to 1 if you have the `H5Pset_all_coll_metadata_ops' function. */
/* #undef HAVE_H5PSET_ALL_COLL_METADATA_OPS */

/* Define to 1 if you have the `H5Pset_deflate' function. */
#define HAVE_H5PSET_DEFLATE 1

/* if true, compile in szip compression in netCDF-4 variables */
#define HAVE_H5Z_SZIP 1

/* Define to 1 if you have the <hdf5.h> header file. */
#define HAVE_HDF5_H 1

/* Define to 1 if the system has the type `int64'. */
/* #undef HAVE_INT64 */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `crypto' library (-lcrypto). */
/* #undef HAVE_LIBCRYPTO */

/* libcurl version is 7.66 or later */
#define HAVE_LIBCURL_766 1

/* Define to 1 if you have the `df' library (-ldf). */
/* #undef HAVE_LIBDF */

/* Define to 1 if you have the <libgen.h> header file. */
#define HAVE_LIBGEN_H 1

/* Define to 1 if you have the `jpeg' library (-ljpeg). */
/* #undef HAVE_LIBJPEG */

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* Define to 1 if you have the `mfhdf' library (-lmfhdf). */
/* #undef HAVE_LIBMFHDF */

/* Define to 1 if you have the `pnetcdf' library (-lpnetcdf). */
/* #undef HAVE_LIBPNETCDF */

/* Define to 1 if you have the `ssl' library (-lssl). */
/* #undef HAVE_LIBSSL */

/* if true, use libxml2 */
#define HAVE_LIBXML2 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if the system has the type `longlong'. */
/* #undef HAVE_LONGLONG */

/* Define to 1 if the system has the type `long long int'. */
#define HAVE_LONG_LONG_INT 1

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <mfhdf.h> header file. */
/* #undef HAVE_MFHDF_H */

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have the `mktemp' function. */
#define HAVE_MKTEMP 1

/* Define to 1 if you have the `mmap' function. */
#define HAVE_MMAP 1

/* Define to 1 if the system has the type `mode_t'. */
#define HAVE_MODE_T 1

/* Define to 1 if you have the `MPI_Comm_f2c' function. */
/* #undef HAVE_MPI_COMM_F2C */

/* Define to 1 if you have the `MPI_Info_f2c' function. */
/* #undef HAVE_MPI_INFO_F2C */

/* Define to 1 if you have the `mremap' function. */
#define HAVE_MREMAP 1

/* Define to 1 if the system has the type `ptrdiff_t'. */
#define HAVE_PTRDIFF_T 1

/* Define to 1 if you have the `random' function. */
#define HAVE_RANDOM 1

/* Define to 1 if the system has the type `schar'. */
/* #undef HAVE_SCHAR */

/* Define to 1 if the system has the type `size64_t'. */
/* #undef HAVE_SIZE64_T */

/* Define to 1 if the system has the type `size_t'. */
#define HAVE_SIZE_T 1

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if the system has the type `ssize64_t'. */
/* #undef HAVE_SSIZE64_T */

/* Define to 1 if the system has the type `ssize_t'. */
#define HAVE_SSIZE_T 1

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
#define HAVE_STRLCAT 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if you have the `strtoull' function. */
#define HAVE_STRTOULL 1

/* Define to 1 if `st_blksize' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_BLKSIZE 1

/* Define to 1 if the system has the type `struct timespec'. */
#define HAVE_STRUCT_TIMESPEC 1

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/xattr_h> header file. */
/* #undef HAVE_SYS_XATTR_H */

/* if true, libsz (==szip) is available */
#define HAVE_SZ 1

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if the system has the type `uchar'. */
/* #undef HAVE_UCHAR */

/* Define to 1 if the system has the type `uint'. */
#define HAVE_UINT 1

/* Define to 1 if the system has the type `uint64'. */
/* #undef HAVE_UINT64 */

/* Define to 1 if the system has the type `uint64_t'. */
#define HAVE_UINT64_T 1

/* Define to 1 if the system has the type `uintptr_t'. */
#define HAVE_UINTPTR_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type `unsigned long long int'. */
#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* Define to 1 if the system has the type `ushort'. */
#define HAVE_USHORT 1

/* if true, zstd library is available */
#define HAVE_ZSTD 1

/* Define to 1 if you have the <zstd.h> header file. */
#define HAVE_ZSTD_H 1

/* Define to 1 if the system has the type `_off64_t'. */
/* #undef HAVE__OFF64_T */

/* if true, use collective metadata ops in parallel netCDF-4 */
/* #undef HDF5_HAS_COLL_METADATA_OPS */

/* if true, hdf5 has parallelism enabled */
/* #undef HDF5_PARALLEL */

/* if true, HDF5 is at least version 1.10.3 and allows parallel I/O with zip
   */
#define HDF5_SUPPORTS_PAR_FILTERS 1

/* if true, HDF5 paths can be utf-8 */
#define HDF5_UTF8_PATHS 1

/* do large file tests */
/* #undef LARGE_FILE_TESTS */

/* If true, turn on logging. */
/* #undef LOGGING */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* min blocksize for posixio. */
#define NCIO_MINBLOCKSIZE 256

/* Extra pairs for _NCProperties */
#define NCPROPERTIES_EXTRA ""

/* Dispatch table version. */
#define NC_DISPATCH_VERSION 5

/* If true, enable nc_finalize via atexit() */
#define NETCDF_ENABLE_ATEXIT_FINALIZE 1

/* if true, support byte-range read of remote datasets. */
#define NETCDF_ENABLE_BYTERANGE 1

/* if true, enable CDF5 Support */
#define NETCDF_ENABLE_CDF5 1

/* if true, build DAP Client */
#define NETCDF_ENABLE_DAP 1

/* if true, build DAP4 Client */
#define NETCDF_ENABLE_DAP4 1

/* if true, do remote tests */
/* #undef NETCDF_ENABLE_DAP_REMOTE_TESTS */

/* if true, do remote external tests */
/* #undef NETCDF_ENABLE_EXTERNAL_SERVER_TESTS */

/* if true, use HDF5 */
#define NETCDF_ENABLE_HDF5 1

/* if true, support byte-range using hdf5 virtual file driver. */
#define NETCDF_ENABLE_HDF5_ROS3 1

/* If true, enable legacy macros in netcdf.h */
#define NETCDF_ENABLE_LEGACY_MACROS 1

/* if true, build NCZarr Client */
#define NETCDF_ENABLE_NCZARR 1

/* if true, enable NCZarr filters */
#define NETCDF_ENABLE_NCZARR_FILTERS 1

/* If true, then libzip found */
/* #undef NETCDF_ENABLE_NCZARR_ZIP */

/* if true, support dynamically loaded plugins */
#define NETCDF_ENABLE_PLUGINS 1

/* if true, enable quantize support */
#define NETCDF_ENABLE_QUANTIZE 1

/* if true, build netcdf-c with S3 support enabled */
/* #undef NETCDF_ENABLE_S3 */

/* If true, then use aws S3 library */
/* #undef NETCDF_ENABLE_S3_AWS */

/* If true, then use internal S3 library */
/* #undef NETCDF_ENABLE_S3_INTERNAL */

/* control S3 testing. */
/* #undef NETCDF_ENABLE_S3_TESTALL */

/* If true, enable nc_set_log_level function. */
/* #undef NETCDF_ENABLE_SET_LOG_LEVEL */

/* Final Install Dir */
#define NETCDF_PLUGIN_INSTALL_DIR ""

/* Final Search Path */
#define NETCDF_PLUGIN_SEARCH_PATH "/usr/local/hdf5/lib/plugin"

/* do not build the netCDF version 2 API */
/* #undef NO_NETCDF_2 */

/* Name of package */
#define PACKAGE "netcdf-c"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "support-netcdf@unidata.ucar.edu"

/* Define to the full name of this package. */
#define PACKAGE_NAME "netCDF"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "netCDF 4.10.0-development"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "netcdf-c"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "4.10.0-development"

/* dreg.c usable */
/* #undef REGEDIT */

/* the testservers for remote tests. */
#define REMOTETESTSERVERS "remotetest.unidata.ucar.edu"

/* S3 test bucket */
#define S3TESTBUCKET "unidata-zarr-test-data"

/* S3 test path prefix */
#define S3TESTSUBTREE "netcdf-c"

/* The size of `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of `float', as computed by sizeof. */
#define SIZEOF_FLOAT 4

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 8

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `off_t', as computed by sizeof. */
#define SIZEOF_OFF_T 8

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `size_t', as computed by sizeof. */
#define SIZEOF_SIZE_T 8

/* The size of `ssize_t', as computed by sizeof. */
#define SIZEOF_SSIZE_T 8

/* The size of `uchar', as computed by sizeof. */
/* #undef SIZEOF_UCHAR */

/* The size of `uint', as computed by sizeof. */
#define SIZEOF_UINT 4

/* The size of `unsigned char', as computed by sizeof. */
#define SIZEOF_UNSIGNED_CHAR 1

/* The size of `unsigned int', as computed by sizeof. */
/* #undef SIZEOF_UNSIGNED_INT */

/* The size of `unsigned long long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* The size of `unsigned short int', as computed by sizeof. */
/* #undef SIZEOF_UNSIGNED_SHORT_INT */

/* The size of `ushort', as computed by sizeof. */
#define SIZEOF_USHORT 2

/* The size of `void*', as computed by sizeof. */
#define SIZEOF_VOIDP 8

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Place to put very large netCDF test files. */
#define TEMP_LARGE "."

/* S3 working path */
#define TESTUID 1755030456

/* dispatch table for user-defined format 0. */
/* #undef UDF0_DISPATCH */

/* function to get dispatch table for user-defined format 0. */
/* #undef UDF0_DISPATCH_FUNC */

/* dispatch table for user-defined format 1. */
/* #undef UDF1_DISPATCH */

/* function to get dispatch table for user-defined format 1. */
/* #undef UDF1_DISPATCH_FUNC */

/* if true, build DAP Client */
#define USE_DAP 1

/* set this to use extreme numbers in tests */
#define USE_EXTREME_NUMBERS 1

/* if true, use ffio instead of posixio */
/* #undef USE_FFIO */

/* if true, include experimental fsync code */
/* #undef USE_FSYNC */

/* if true, use HDF4 too */
/* #undef USE_HDF4 */

/* If true, use use wget to fetch some sample HDF4 data, and then test against
   it. */
/* #undef USE_HDF4_FILE_TESTS */

/* if true, use HDF5 */
#define USE_HDF5 1

/* if true, use mmap for in-memory files */
/* #undef USE_MMAP */

/* if true, build netCDF-4 */
#define USE_NETCDF4 1

/* build the netCDF version 2 API */
#define USE_NETCDF_2 1

/* if true, PnetCDF or parallel netcdf-4 is in use */
/* #undef USE_PARALLEL */

/* if true, parallel netcdf-4 is in use */
/* #undef USE_PARALLEL4 */

/* if true, PnetCDF is used */
/* #undef USE_PNETCDF */

/* if true, use stdio instead of posixio */
/* #undef USE_STDIO */

/* if true, enable strict null byte header padding */
/* #undef USE_STRICT_NULL_BYTE_HEADER_PADDING */

/* if true, use user-defined format 0 in utilities */
/* #undef USE_UDF0 */

/* if true, use user-defined format 1 in utilities */
/* #undef USE_UDF1 */

/* Version number of package */
#define VERSION "4.10.0-development"

/* windows version build */
#define WINVERBUILD 0

/* windows version major */
#define WINVERMAJOR 0

/* control S3 testing. */
#define WITH_S3_TESTING no

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to 1 if type `char' is unsigned and your compiler does not
   predefine this macro.  */
#ifndef __CHAR_UNSIGNED__
/* # undef __CHAR_UNSIGNED__ */
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to the type of an unsigned integer type wide enough to hold a
   pointer, if such a type exists, and if the system does not define it. */
/* #undef uintptr_t */

#include "ncconfigure.h"
