# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_stella_cartographer_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED stella_cartographer_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(stella_cartographer_FOUND FALSE)
  elseif(NOT stella_cartographer_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(stella_cartographer_FOUND FALSE)
  endif()
  return()
endif()
set(_stella_cartographer_CONFIG_INCLUDED TRUE)

# output package information
if(NOT stella_cartographer_FIND_QUIETLY)
  message(STATUS "Found stella_cartographer: 2.1.2 (${stella_cartographer_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'stella_cartographer' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${stella_cartographer_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(stella_cartographer_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${stella_cartographer_DIR}/${_extra}")
endforeach()
