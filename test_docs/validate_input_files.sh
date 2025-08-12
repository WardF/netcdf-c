#!/bin/bash
# Validate all files in our reorganized INPUT section exist

set -e

SRC_DIR="/home/runner/work/netcdf-c/netcdf-c"

echo "=== Validating all INPUT files in reorganized Doxyfile.in ==="

# Extract INPUT files from our reorganized section (lines with file paths)
input_files=(
    # Main introduction and overview
    "$SRC_DIR/docs/mainpage.dox"
    "$SRC_DIR/docs/groups.dox"
    
    # Getting started guides
    "$SRC_DIR/docs/building-with-cmake.md"
    "$SRC_DIR/docs/install-fortran.md"
    "$SRC_DIR/docs/windows-binaries.md"
    "$SRC_DIR/docs/quickstart_env.md"
    "$SRC_DIR/docs/quickstart_paths.md"
    "$SRC_DIR/docs/quickstart_filters.md"
    
    # User guides and tutorials
    "$SRC_DIR/docs/tutorial.dox"
    "$SRC_DIR/docs/FAQ.md"
    
    # Core API reference
    "$SRC_DIR/include/netcdf.h"
    "$SRC_DIR/include/netcdf_mem.h"
    "$SRC_DIR/include/netcdf_par.h"
    "$SRC_DIR/include/netcdf_filter.h"
    
    # Advanced topics
    "$SRC_DIR/docs/inmemory.md"
    "$SRC_DIR/docs/filters.md"
    "$SRC_DIR/docs/pluginpath.md"
    "$SRC_DIR/docs/quantize.md"
    "$SRC_DIR/docs/byterange.md"
    "$SRC_DIR/docs/auth.md"
    "$SRC_DIR/docs/cloud.md"
    "$SRC_DIR/docs/nczarr.md"
    "$SRC_DIR/docs/indexing.dox"
    
    # Developer documentation
    "$SRC_DIR/docs/internal.md"
    "$SRC_DIR/docs/dispatch.md"
    "$SRC_DIR/docs/inmeminternal.dox"
    "$SRC_DIR/docs/testserver.dox"
    "$SRC_DIR/docs/notes.md"
    
    # Reference materials
    "$SRC_DIR/RELEASE_NOTES.md"
    "$SRC_DIR/docs/attribute_conventions.md"
    "$SRC_DIR/docs/file_format_specifications.md"
    "$SRC_DIR/docs/all-error-codes.md"
    "$SRC_DIR/docs/COPYRIGHT.md"
    "$SRC_DIR/docs/credits.md"
    
    # Examples
    "$SRC_DIR/examples/C/simple_xy_wr.c"
    "$SRC_DIR/examples/C/simple_xy_rd.c"
    "$SRC_DIR/examples/C/sfc_pres_temp_wr.c"
    "$SRC_DIR/examples/C/sfc_pres_temp_rd.c"
    "$SRC_DIR/examples/C/pres_temp_4D_wr.c"
    "$SRC_DIR/examples/C/pres_temp_4D_rd.c"
    "$SRC_DIR/examples/C/simple_nc4_wr.c"
    "$SRC_DIR/examples/C/simple_nc4_rd.c"
    "$SRC_DIR/examples/C/simple_xy_nc4_wr.c"
    "$SRC_DIR/examples/C/simple_xy_nc4_rd.c"
    "$SRC_DIR/examples/C/filter_example.c"
)

# Add source files
source_files=(
    # Core dispatch layer
    "$SRC_DIR/libdispatch/dfile.c"
    "$SRC_DIR/libdispatch/ddim.c"
    "$SRC_DIR/libdispatch/dvar.c"
    "$SRC_DIR/libdispatch/dvarget.c"
    "$SRC_DIR/libdispatch/dvarinq.c"
    "$SRC_DIR/libdispatch/dvarput.c"
    "$SRC_DIR/libdispatch/datt.c"
    "$SRC_DIR/libdispatch/dattinq.c"
    "$SRC_DIR/libdispatch/dattget.c"
    "$SRC_DIR/libdispatch/dattput.c"
    "$SRC_DIR/libdispatch/dgroup.c"
    "$SRC_DIR/libdispatch/dtype.c"
    "$SRC_DIR/libdispatch/dcompound.c"
    "$SRC_DIR/libdispatch/denum.c"
    "$SRC_DIR/libdispatch/dvlen.c"
    "$SRC_DIR/libdispatch/dopaque.c"
    "$SRC_DIR/libdispatch/dparallel.c"
    "$SRC_DIR/libdispatch/derror.c"
    "$SRC_DIR/libdispatch/dv2i.c"
    "$SRC_DIR/libdispatch/dcopy.c"
    "$SRC_DIR/libdispatch/dfilter.c"
    
    # NetCDF-4 implementation
    "$SRC_DIR/libsrc4/nc4var.c"
    "$SRC_DIR/libsrc4/nc4dim.c"
    "$SRC_DIR/libsrc4/nc4attr.c"
    "$SRC_DIR/libsrc4/nc4grp.c"
    "$SRC_DIR/libsrc4/nc4type.c"
    "$SRC_DIR/libsrc4/nc4cache.c"
    "$SRC_DIR/libsrc4/nc4internal.c"
    "$SRC_DIR/libsrc4/ncfunc.c"
    "$SRC_DIR/libsrc4/nc4dispatch.c"
    
    # HDF5 backend
    "$SRC_DIR/libhdf5/nc4hdf.c"
    "$SRC_DIR/libhdf5/nc4info.c"
    
    # NCZarr backend
    "$SRC_DIR/libnczarr/zarr.c"
)

# Combine all files
all_files=("${input_files[@]}" "${source_files[@]}")

total_files=${#all_files[@]}
missing_files=0
found_files=0

echo "Checking $total_files files..."
echo ""

for file in "${all_files[@]}"; do
    if [ -f "$file" ]; then
        echo "✓ $file"
        ((found_files++))
    else
        echo "✗ MISSING: $file"
        ((missing_files++))
    fi
done

echo ""
echo "=== Summary ==="
echo "Total files: $total_files"
echo "Found: $found_files"
echo "Missing: $missing_files"

if [ $missing_files -eq 0 ]; then
    echo ""
    echo "✓ ALL INPUT FILES EXIST - Reorganization is valid!"
    exit 0
else
    echo ""
    echo "✗ Some files are missing - need to update INPUT section"
    exit 1
fi