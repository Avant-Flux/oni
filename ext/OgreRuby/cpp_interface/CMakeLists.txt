cmake_minimum_required(VERSION 2.6)

project(OgreCInterface)
 
if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()
 
set(CMAKE_DEBUG_POSTFIX "_d")
 
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

set(HDRS
	./ogre.h
)
 
set(SRCS
	./ogre.cpp
)

include_directories(
	./../../vendor/build_ogre/dist/lib/libOgreBase.a
)

# Create static library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/lib)
add_library(OgreInterface STATIC ${HDRS} ${SRCS})
target_link_libraries(OgreInterface ${OGRE_LIBRARIES} ${OIS_LIBRARIES})

# Create folder for created libraries
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/lib)