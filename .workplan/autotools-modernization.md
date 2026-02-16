# Autotools Build System Modernization Plan

## Current State Analysis

### Current Autotools Configuration
- **Autoconf Version**: 2.59+ (AC_PREREQ([2.59]))
- **Configure Script**: Well-structured configure.ac
- **Makefiles**: Comprehensive Makefile.am structure
- **Version Management**: 4.10.0-development with proper versioning
- **Libtool**: Integrated for library building

### Strengths of Current System
- Comprehensive platform detection
- Well-organized conditional compilation
- Proper shared library versioning
- Extensive feature detection and optional dependencies
- Cross-compilation support

## Modernization Opportunities

### 1. Autoconf Version Upgrade
**Priority: HIGH**
- **Current**: AC_PREREQ([2.59]) - from 2005
- **Recommended**: AC_PREREQ([2.71]) - current stable
- **Benefits**: Access to modern autoconf features, better platform support
- **Risk**: Low - autoconf maintains excellent backward compatibility

### 2. Build System Features Modernization
**Priority: MEDIUM**

#### A. Modern Autoconf Macros
```autoconf
# Current approach may use older patterns
# Modernize to use current best practices:
AC_CHECK_HEADERS([header.h], [], [AC_MSG_ERROR([Required header not found])])
AC_CHECK_FUNCS([func], [], [AC_MSG_ERROR([Required function not found])])
```

#### B. Compiler Feature Detection
```autoconf
# Add modern C standard detection
AC_PROG_CC_C11
# Or for C17
AC_PROG_CC_C17
```

### 3. Makefile.am Modernization
**Priority: MEDIUM**

#### A. Non-recursive Make (where appropriate)
- Consider converting some deeply nested Makefiles to non-recursive structure
- Benefits: Faster builds, better dependency tracking
- Risk: Significant restructuring required

#### B. Modern Automake Features
```makefile
# Use modern automake constructs
AM_CFLAGS = -Wall -Wextra -std=c11
AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_builddir)/include
```

### 4. Cross-compilation Enhancement
**Priority: LOW**
- Modern cross-compilation detection
- Better support for embedded platforms
- Enhanced Windows cross-compilation

## Specific Modernization Tasks

### 1. Configure.ac Updates

#### A. Version Requirements
```autoconf
# Update minimum requirements
AC_PREREQ([2.71])
AC_INIT([netCDF],[4.10.0-development],[support-netcdf@unidata.ucar.edu],[netcdf-c])
```

#### B. Modern Macro Usage
```autoconf
# Use modern compiler detection
AC_PROG_CC
AC_PROG_CC_C11  # Add explicit C11 requirement

# Modern header checks with error handling
AC_CHECK_HEADERS([stdlib.h string.h unistd.h], [], 
    [AC_MSG_ERROR([Required standard headers not found])])
```

#### C. Feature Test Macros
```autoconf
# Use AS_IF for cleaner conditionals
AS_IF([test "x$enable_hdf5" = "xyes"], 
    [AC_CHECK_LIB([hdf5], [H5Fopen], [have_hdf5=yes], [have_hdf5=no])],
    [have_hdf5=no])
```

### 2. Makefile.am Improvements

#### A. Compiler Flags Modernization
```makefile
# Set consistent C standard across all modules
AM_CFLAGS = -std=c11 -Wall -Wextra -Wpedantic

# Conditional debug flags
if DEBUG
AM_CFLAGS += -g -O0 -DDEBUG
else
AM_CFLAGS += -O2 -DNDEBUG
endif
```

#### B. Dependency Tracking
```makefile
# Ensure proper dependency tracking
AUTOMAKE_OPTIONS = subdir-objects
AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_builddir)/include
```

#### C. Test Integration
```makefile
# Modern test integration
TESTS = $(check_PROGRAMS)
check_PROGRAMS = test_netcdf test_nc4 test_dap

# Use modern test driver
TEST_LOG_DRIVER = $(SHELL) $(top_srcdir)/test-driver-verbose
```

### 3. Library Configuration

#### A. Libtool Modernization
```autoconf
# Use modern libtool initialization
LT_INIT([shared static])
LT_LANG([C])
```

#### B. Version Information
```makefile
# Clear versioning in Makefile.am
libnetcdf_la_LDFLAGS = -version-info $(netCDF_SO_VERSION) -no-undefined
```

### 4. Platform-Specific Enhancements

#### A. Windows Support
```autoconf
# Enhanced Windows detection and support
case $host_os in
    mingw* | cygwin* | msys*)
        # Windows-specific configurations
        ;;
    *)
        # Unix-like systems
        ;;
esac
```

#### B. macOS Support
```autoconf
# Modern macOS framework support
AS_CASE([$host_os],
    [darwin*], [
        # macOS-specific configurations
        LDFLAGS="$LDFLAGS -framework CoreFoundation"
    ])
```

### 5. Build Options Modernization

#### A. Feature Options
```autoconf
# Clear, consistent option definitions
AC_ARG_ENABLE([hdf5],
    [AS_HELP_STRING([--enable-hdf5], [Enable HDF5 support (default: yes)])],
    [enable_hdf5=$enableval],
    [enable_hdf5=yes])
```

#### B. Dependency Detection
```autoconf
# Modern dependency detection patterns
PKG_CHECK_MODULES([HDF5], [hdf5 >= 1.10.0], [have_hdf5=yes], [have_hdf5=no])
```

## Testing and Validation Improvements

### 1. Test Suite Modernization
```makefile
# Modern test organization
TESTS = \
    tests/unit/test_basic \
    tests/integration/test_formats \
    tests/regression/test_compatibility

# Parallel test execution
AM_INIT_AUTOMAKE([parallel-tests])
```

### 2. Coverage Support
```autoconf
# Add coverage support
AC_ARG_ENABLE([coverage],
    [AS_HELP_STRING([--enable-coverage], [Enable coverage testing])],
    [enable_coverage=$enableval],
    [enable_coverage=no])

AS_IF([test "x$enable_coverage" = "xyes"], [
    AX_CODE_COVERAGE
])
```

### 3. Sanitizer Support
```autoconf
# Add sanitizer options
AC_ARG_ENABLE([sanitizers],
    [AS_HELP_STRING([--enable-sanitizers], [Enable sanitizer builds])],
    [enable_sanitizers=$enableval],
    [enable_sanitizers=no])
```

## Documentation Integration

### 1. Doxygen Integration
```autoconf
# Modern doxygen detection
DX_HTML_FEATURE(ON)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_MAN_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN([netCDF], [docs/Doxyfile], [docs])
```

## Implementation Plan

### Phase 1: Core Updates (Immediate)
1. Update autoconf version requirement to 2.71
2. Add explicit C11 standard requirement  
3. Modernize core configure.ac macros
4. Update compiler flag management

### Phase 2: Build Enhancements (Short-term)
1. Modernize Makefile.am files with consistent standards
2. Improve test integration and execution
3. Enhance cross-platform support
4. Add coverage and sanitizer support

### Phase 3: Advanced Features (Medium-term)
1. Consider selective non-recursive make adoption
2. Enhanced dependency management
3. Modern packaging integration
4. Improved developer experience

## Compatibility Considerations

### 1. Backward Compatibility
- Maintain all existing configure options
- Preserve build behavior for existing scripts
- Document any changes in build requirements

### 2. Platform Support
- Ensure continued support for all currently supported platforms
- Test on legacy systems where feasible
- Provide migration guidance for deprecated features

### 3. Tool Requirements
- Document updated tool version requirements
- Provide guidance for building with older autotools where necessary

## Success Metrics

- Faster configure times
- Cleaner configure output
- Better error messages for missing dependencies
- Improved cross-compilation support
- Enhanced developer experience
- Maintained platform compatibility

## Integration with CMake

Since the project supports both build systems:
- Ensure feature parity between autotools and CMake
- Maintain consistent behavior across both systems
- Document differences and migration paths
- Consider shared configuration where possible