# CMake Build System Modernization Plan

## Current State Analysis

### Current CMake Configuration
- **Minimum Version**: CMake 3.20.0 (already modern)
- **Languages**: C and CXX
- **Version**: 4.10.0-development
- **Project Structure**: Well-organized with custom modules

### Strengths of Current System
- Uses modern CMake minimum version (3.20+)
- Proper project() call with metadata
- Custom module directory structure
- Version management system in place

## Modernization Opportunities

### 1. Target-Based Design Enhancement
**Priority: MEDIUM**
- **Current**: Mix of global and target-specific properties
- **Opportunity**: Full migration to target-based approach
- **Benefits**: Better dependency management, cleaner build configuration

### 2. CMake Best Practices Adoption
**Priority: HIGH**

#### A. Modern Target Properties
```cmake
# Instead of setting global compile flags
target_compile_features(netcdf PRIVATE c_std_11)
target_compile_options(netcdf PRIVATE -Wall -Wextra)
```

#### B. Generator Expressions
- Use generator expressions for platform-specific settings
- Conditional compilation based on configuration

#### C. Interface Libraries for Common Settings
- Create interface targets for common compiler flags
- Shared configuration across multiple targets

### 3. Dependency Management Modernization
**Priority: HIGH**
- **find_package()**: Ensure all dependencies use modern find modules
- **Package Config**: Generate proper CMake package config files
- **Targets**: Export proper CMake targets for downstream projects

### 4. Installation and Packaging
**Priority: MEDIUM**
- **CMake Package Registry**: Proper package registration
- **Export Sets**: Clean target export configuration
- **CPack Integration**: Modern packaging support

### 5. Testing Integration
**Priority: HIGH**
- **CTest Integration**: Full CTest integration (partially done)
- **Coverage Reports**: CMake-integrated coverage reporting
- **Sanitizers**: Easy sanitizer builds

### 6. Cross-Platform Improvements
**Priority: MEDIUM**
- **Platform Detection**: Modern platform-specific configurations
- **Toolchain Files**: Support for cross-compilation
- **Windows Support**: Enhanced Windows/MSVC support

## Specific Modernization Tasks

### 1. C Standard Configuration
```cmake
# Current: No explicit C standard
# Proposed:
target_compile_features(netcdf PUBLIC c_std_11)
# Or for C17:
target_compile_features(netcdf PUBLIC c_std_17)
```

### 2. Compiler Warning Configuration
```cmake
# Create interface library for common warnings
add_library(netcdf_warnings INTERFACE)
target_compile_options(netcdf_warnings INTERFACE
    $<$<COMPILE_LANGUAGE:C>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wno-unused-parameter>
)
```

### 3. Dependency Target Creation
```cmake
# Ensure all dependencies are properly targetized
find_package(HDF5 REQUIRED COMPONENTS C)
target_link_libraries(netcdf PRIVATE HDF5::HDF5)
```

### 4. Configuration Header Modernization
```cmake
# Use configure_file for version information
configure_file(
    ${CMAKE_SOURCE_DIR}/include/netcdf_meta.h.in
    ${CMAKE_BINARY_DIR}/include/netcdf_meta.h
    @ONLY
)
```

### 5. Installation Modernization
```cmake
# Modern installation with proper CMake package support
install(TARGETS netcdf
    EXPORT netCDFTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT netCDFTargets
    FILE netCDFTargets.cmake
    NAMESPACE netCDF::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/netCDF
)
```

## Build Options Modernization

### 1. Feature Options
- Use `option()` with clear descriptions
- Group related options
- Provide good defaults

### 2. Cache Variables
- Minimize cache pollution
- Use proper variable types
- Clear documentation strings

### 3. Build Types
- Support for RelWithDebInfo, MinSizeRel
- Custom build types for development
- Sanitizer build configurations

## Testing and Validation

### 1. CTest Integration
```cmake
# Enable testing
enable_testing()

# Modern test addition
add_test(NAME unit_tests 
         COMMAND $<TARGET_FILE:netcdf_test>
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
```

### 2. Coverage Support
```cmake
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
if(ENABLE_COVERAGE)
    target_compile_options(netcdf PRIVATE --coverage)
    target_link_libraries(netcdf PRIVATE --coverage)
endif()
```

## Package Configuration

### 1. Modern Config File
Generate proper CMake package configuration:
```cmake
# netCDFConfig.cmake.in
include(CMakeFindDependencyMacro)
find_dependency(HDF5)
include("${CMAKE_CURRENT_LIST_DIR}/netCDFTargets.cmake")
```

### 2. Version File
```cmake
write_basic_package_version_file(
    netCDFConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
```

## Implementation Plan

### Phase 1: Core Modernization (Immediate)
1. Add explicit C standard requirements
2. Modernize compiler warning flags
3. Convert to target-based properties where missing
4. Improve dependency management

### Phase 2: Enhanced Configuration (Short-term)
1. Modernize installation and export
2. Improve CTest integration
3. Add coverage support
4. Enhance cross-platform support

### Phase 3: Advanced Features (Medium-term)
1. CPack integration for packaging
2. Sanitizer build configurations
3. Enhanced development tools integration
4. Performance optimization options

## Success Metrics

- Clean CMake configuration without warnings
- Proper target exports for downstream projects
- Comprehensive test integration
- Cross-platform build verification
- Reduced configuration complexity

## Compatibility Considerations

- Maintain compatibility with existing CMake workflows
- Preserve all current build options and features
- Ensure downstream projects continue to work
- Gradual migration approach to minimize disruption