# NetCDF-C Library
NetCDF-C is a C library for scientific data access that provides support for the creation, access, and sharing of array-oriented scientific data. It supports multiple data formats including netCDF-3 (classic), netCDF-4 (HDF5-based), CDF-5, and cloud-optimized formats like Zarr.

**Always reference these instructions first and fallback to search or bash commands only when you encounter unexpected information that does not match the info here.**

## Working Effectively

### Dependencies Installation
Install all required dependencies before building:
```bash
sudo apt update && sudo apt install -y libhdf5-dev libcurl4-openssl-dev zlib1g-dev m4 autoconf automake libtool flex bison doxygen cmake build-essential
```

### Building with CMake (Recommended)
**NEVER CANCEL: Configuration takes 10 seconds. Build takes 30 seconds. Tests take 1 minute. Set timeout to 10+ minutes.**
```bash
mkdir build && cd build
cmake .. -DNETCDF_ENABLE_HDF5=ON -DNETCDF_ENABLE_DAP=ON -DNETCDF_ENABLE_TESTS=ON  # Takes ~10 seconds
make -j$(nproc)  # Takes ~30 seconds. NEVER CANCEL.
```

### Building with Autotools (Alternative)
**NEVER CANCEL: Build takes 20-30 seconds. Set timeout to 10+ minutes.**
```bash
./bootstrap  # Generate configure script (if building from git)
export CPPFLAGS="-I/usr/include/hdf5/serial"
export LDFLAGS="-L/usr/lib/x86_64-linux-gnu/hdf5/serial"
mkdir autotools-build && cd autotools-build
../configure --enable-hdf5 --enable-dap --disable-dap-remote-tests
make -j$(nproc)  # Takes ~20 seconds. NEVER CANCEL.
```

### Testing
**NEVER CANCEL: Tests take 1 minute. Set timeout to 5+ minutes.**
```bash
# CMake
cd build && ctest --output-on-failure  # Takes ~55 seconds, 230+ tests, expect 2 DAP remote test failures

# Autotools 
cd autotools-build && make check  # Similar timing and results
```

**Expected Results**: 99% test pass rate (230/232 tests). The 2 DAP remote test failures are normal when remote test servers are not configured.

### Basic Validation
Always run basic validation after building:
```bash
# Test examples (CMake)
cd build/examples/C
./C_tests_simple_xy_wr && ./C_tests_simple_xy_rd
# Expected output: "*** SUCCESS writing example file simple_xy.nc!" then "*** SUCCESS reading example file simple_xy.nc!"

# Test examples (Autotools)  
cd autotools-build/examples/C
./simple_xy_wr && ./simple_xy_rd
# Expected output: Same success messages as above

# Test utilities
./ncdump/ncdump examples/C/simple_xy.nc  # Should display netCDF data structure
# Expected output: "netcdf simple_xy { dimensions: x = 6 ; y = 12 ; variables: int data(x, y) ; ..."
```

## Validation

### Manual Testing Scenarios
**ALWAYS test complete end-to-end scenarios after making changes:**

1. **Library Creation/Reading Test**: Run the simple_xy example to create a netCDF file and read it back
2. **Utility Test**: Use ncdump to verify file contents are displayed correctly  
3. **Format Support Test**: Test creation of netCDF-3, netCDF-4, and CDF-5 format files
4. **Build System Test**: Verify both CMake and autotools can build successfully

### Critical Timing Expectations
- **Configuration**: 10 seconds for CMake, 11 seconds for autotools
- **Build**: 20-30 seconds (autotools), 30 seconds (CMake) with -j$(nproc)
- **Tests**: 55-60 seconds for full test suite (230+ tests)
- **NEVER CANCEL** any of these operations - they may appear to hang but are processing

### Validation Commands
Always run these validation steps:
```bash
# Build validation
make -j$(nproc)  # Should complete without errors

# Test validation  
make check        # (autotools) or ctest (CMake) - should pass 99% of tests

# Functionality validation
cd examples/C && ./simple_xy_wr && ./simple_xy_rd  # Should create and read file successfully
```

## Common Tasks

### Key Directories and Their Purposes
- `libsrc/` - Classic netCDF-3 format implementation
- `libsrc4/` - netCDF-4/HDF5 format implementation  
- `libdispatch/` - Common dispatch layer for all formats
- `libnczarr/` - Zarr format support implementation
- `libdap2/`, `libdap4/` - DAP (remote data access) protocol support
- `ncdump/` - ncdump utility for examining netCDF files
- `ncgen/` - ncgen utility for generating netCDF files from CDL
- `examples/` - Example programs demonstrating library usage
- `nc_test/`, `nc_test4/`, `nczarr_test/` - Test suites for different components

### Build Configuration Options
**CMake Options** (add to cmake command):
- `-DNETCDF_ENABLE_HDF5=ON/OFF` - Enable/disable netCDF-4 support
- `-DNETCDF_ENABLE_DAP=ON/OFF` - Enable/disable remote data access
- `-DNETCDF_ENABLE_NCZARR=ON/OFF` - Enable/disable Zarr format support
- `-DNETCDF_ENABLE_TESTS=ON/OFF` - Enable/disable test suite
- `-DBUILD_SHARED_LIBS=ON/OFF` - Build shared/static libraries

**Autotools Options** (add to configure command):
- `--enable-hdf5` / `--disable-hdf5` - netCDF-4 support
- `--enable-dap` / `--disable-dap` - Remote data access
- `--disable-dap-remote-tests` - Disable remote server tests (recommended)
- `--enable-shared` / `--disable-shared` - Shared library support

### Debugging Failed Builds
```bash
# Check dependencies
pkg-config --cflags --libs hdf5
which cmake autoconf make gcc

# Check configuration logs
cat config.log        # autotools
cat CMakeCache.txt     # CMake

# Verbose build output
make VERBOSE=1         # CMake
make V=1              # autotools
```

### Code Style and Linting
The project uses its own coding standards. Check for warnings during compilation:
```bash
# Enable extra warnings during build
export CFLAGS="-Wall -Wextra -Wconversion"
```

### Sample Command Outputs

#### Repository Root Structure
```
ls -la /
.github/          # GitHub workflows and configurations
CMakeLists.txt    # CMake build configuration
configure.ac      # Autotools configuration
Makefile.am      # Autotools makefile template
bootstrap        # Script to generate configure script
libsrc/          # Classic netCDF-3 implementation  
libsrc4/         # netCDF-4/HDF5 implementation
libdispatch/     # Common dispatch layer
libnczarr/       # Zarr format support
ncdump/          # ncdump utility
ncgen/           # ncgen utility
examples/        # Example programs
docs/            # Documentation
nc_test*/        # Test suites
README.md        # Project information
INSTALL.md       # Installation instructions
```

#### Configuration Output (CMake)
```bash
cmake .. -DNETCDF_ENABLE_HDF5=ON -DNETCDF_ENABLE_DAP=ON -DNETCDF_ENABLE_TESTS=ON
# Expected: Configuration completes successfully in ~10 seconds
# Shows: HDF5 found, DAP enabled, tests enabled, build files generated
# Output ends with: "Build files have been written to: /path/to/build"
```

#### Build Output Summary
```bash
make -j$(nproc)
# Expected: Successful build in 30 seconds
# Shows: Compilation progress [0%] to [100%], linking, executable creation
# Warnings: Some conversion warnings are normal and expected
# Output ends with: "[100%] Built target [name]"
```

#### Test Results Summary
```bash
ctest --output-on-failure  # or make check
# Expected: 230/232 tests passed (99% pass rate)
# Failed: 2 DAP remote tests (normal when servers unavailable)
# Duration: ~55 seconds total
```

## Troubleshooting

### Common Issues
1. **HDF5 not found**: Install libhdf5-dev or set CPPFLAGS/LDFLAGS to HDF5 location
2. **DAP tests failing**: Use --disable-dap-remote-tests - remote servers may be unavailable
3. **Build hangs**: Don't cancel - builds can take 30+ seconds, tests take 1+ minute
4. **Permission errors**: Use sudo for apt package installation
5. **Missing tools**: Install build-essential, cmake, autotools packages

### Performance Notes
- Use -j$(nproc) for parallel builds to minimize build time
- CMake builds are slightly slower but provide better configuration validation
- Test execution time scales with system performance but averages ~1 minute
- Remote DAP tests may timeout - this is expected and normal

Always validate your changes by running the complete build and test cycle before committing code modifications.