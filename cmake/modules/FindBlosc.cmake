# Searches for an installation of the blosc library. On success, it sets the following variables:
#
#   Blosc_FOUND              Set to true to indicate the blosc library was found
#   Blosc_INCLUDE_DIRS       The directory containing the header file blosc/blosc.h
#   Blosc_LIBRARIES          The libraries needed to use the blosc library
#
# To specify an additional directory to search, set Blosc_ROOT.
#
# Author: Siddhartha Chaudhuri, 2009
#

# Look for the header, first in the user-specified location and then in the system locations
set(Blosc_INCLUDE_DOC "The directory containing the header file blosc.h")
find_path(Blosc_INCLUDE_DIRS NAMES blosc.h blosc/blosc.h PATHS ${Blosc_ROOT} ${Blosc_ROOT}/include DOC ${Blosc_INCLUDE_DOC} NO_DEFAULT_PATH)
if(NOT Blosc_INCLUDE_DIRS)  # now look in system locations
  find_path(Blosc_INCLUDE_DIRS NAMES blosc.h blosc/blosc.h DOC ${Blosc_INCLUDE_DOC})
endif()

set(Blosc_FOUND FALSE)

if(Blosc_INCLUDE_DIRS)
  set(Blosc_LIBRARY_DIRS ${Blosc_INCLUDE_DIRS})

  if("${Blosc_LIBRARY_DIRS}" MATCHES "/include$")
    # Strip off the trailing "/include" in the path.
    get_filename_component(Blosc_LIBRARY_DIRS ${Blosc_LIBRARY_DIRS} PATH)
  endif()

  # Find Blosc libraries
  find_library(Blosc_DEBUG_LIBRARY NAMES bloscd blosc_d libbloscd libblosc_d libblosc
               PATH_SUFFIXES Debug ${CMAKE_LIBRARY_ARCHITECTURE} ${CMAKE_LIBRARY_ARCHITECTURE}/Debug
               PATHS ${Blosc_LIBRARY_DIRS} ${Blosc_LIBRARY_DIRS}/lib ${Blosc_LIBRARY_DIRS}/lib64 NO_DEFAULT_PATH)
  find_library(Blosc_RELEASE_LIBRARY NAMES blosc libblosc
               PATH_SUFFIXES Release ${CMAKE_LIBRARY_ARCHITECTURE} ${CMAKE_LIBRARY_ARCHITECTURE}/Release
               PATHS ${Blosc_LIBRARY_DIRS} ${Blosc_LIBRARY_DIRS}/lib ${Blosc_LIBRARY_DIRS}/lib64 NO_DEFAULT_PATH)


  set(Blosc_LIBRARIES )
  if(Blosc_DEBUG_LIBRARY AND Blosc_RELEASE_LIBRARY)
    set(Blosc_LIBRARIES debug ${Blosc_DEBUG_LIBRARY} optimized ${Blosc_RELEASE_LIBRARY})
  elseif(Blosc_DEBUG_LIBRARY)
    set(Blosc_LIBRARIES ${Blosc_DEBUG_LIBRARY})
  elseif(Blosc_RELEASE_LIBRARY)
    set(Blosc_LIBRARIES ${Blosc_RELEASE_LIBRARY})
  endif()

  if(Blosc_LIBRARIES)
    set(Blosc_FOUND TRUE)
  endif()
endif()

if(Blosc_FOUND)
#  if(NOT Blosc_FIND_QUIETLY)
    message(STATUS "Found Blosc: headers at ${Blosc_INCLUDE_DIRS}, libraries at ${Blosc_LIBRARY_DIRS}")
    message(STATUS "	library is ${Blosc_LIBRARIES}")    
#  endif()
else()
  if(Blosc_FIND_REQUIRED)
    message(FATAL_ERROR "Blosc library not found")
  endif()
endif()
