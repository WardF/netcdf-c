# Searches for an installation of the bz2 library. On success, it sets the following variables:
#
#   Bz2_FOUND              Set to true to indicate the bz2 library was found
#   Bz2_INCLUDE_DIRS       The directory containing the header file bz2/bz2.h
#   Bz2_LIBRARIES          The libraries needed to use the bz2 library
#
# To specify an additional directory to search, set Bz2_ROOT.
#
# Author: Siddhartha Chaudhuri, 2009
#

# Look for the header, first in the user-specified location and then in the system locations
set(Bz2_INCLUDE_DOC "The directory containing the header file bz2.h")
find_path(Bz2_INCLUDE_DIRS NAMES bz2.h bz2/bz2.h PATHS ${Bz2_ROOT} ${Bz2_ROOT}/include DOC ${Bz2_INCLUDE_DOC} NO_DEFAULT_PATH)
if(NOT Bz2_INCLUDE_DIRS)  # now look in system locations
  find_path(Bz2_INCLUDE_DIRS NAMES bzlib.h DOC ${Bz2_INCLUDE_DOC})
endif()

set(Bz2_FOUND FALSE)

if(Bz2_INCLUDE_DIRS)
  set(Bz2_LIBRARY_DIRS ${Bz2_INCLUDE_DIRS})

  if("${Bz2_LIBRARY_DIRS}" MATCHES "/include$")
    # Strip off the trailing "/include" in the path.
    get_filename_component(Bz2_LIBRARY_DIRS ${Bz2_LIBRARY_DIRS} PATH)
  endif()

  if(EXISTS "${Bz2_LIBRARY_DIRS}/lib")
    set(Bz2_LIBRARY_DIRS ${Bz2_LIBRARY_DIRS}/lib)
  endif()

  # Find Bz2 libraries
  find_library(Bz2_DEBUG_LIBRARY NAMES bz2d bz2_d libbz2d libbz2_d libbz2
               PATH_SUFFIXES Debug ${CMAKE_LIBRARY_ARCHITECTURE} ${CMAKE_LIBRARY_ARCHITECTURE}/Debug
               PATHS ${Bz2_LIBRARY_DIRS} NO_DEFAULT_PATH)
  find_library(Bz2_RELEASE_LIBRARY NAMES bz2 libbz2
               PATH_SUFFIXES Release ${CMAKE_LIBRARY_ARCHITECTURE} ${CMAKE_LIBRARY_ARCHITECTURE}/Release
               PATHS ${Bz2_LIBRARY_DIRS} NO_DEFAULT_PATH)

  set(Bz2_LIBRARIES )
  if(Bz2_DEBUG_LIBRARY AND Bz2_RELEASE_LIBRARY)
    set(Bz2_LIBRARIES debug ${Bz2_DEBUG_LIBRARY} optimized ${Bz2_RELEASE_LIBRARY})
  elseif(Bz2_DEBUG_LIBRARY)
    set(Bz2_LIBRARIES ${Bz2_DEBUG_LIBRARY})
  elseif(Bz2_RELEASE_LIBRARY)
    set(Bz2_LIBRARIES ${Bz2_RELEASE_LIBRARY})
  endif()

  if(Bz2_LIBRARIES)
    set(Bz2_FOUND TRUE)
  endif()
endif()

if(Bz2_FOUND)
#  if(NOT Bz2_FIND_QUIETLY)
    message(STATUS "Found Bz2: headers at ${Bz2_INCLUDE_DIRS}, libraries at ${Bz2_LIBRARY_DIRS}")
    message(STATUS "	library is ${Bz2_LIBRARIES}")    
#  endif()
else()
  if(Bz2_FIND_REQUIRED)
    message(FATAL_ERROR "Bz2 library not found")
  endif()
endif()
