#/*
#-----------------------------------------------------------------------------
#Filename:    CMakeLists.txt
#-----------------------------------------------------------------------------
#
#This source file is part of the
#   ___                 __    __ _ _    _ 
#  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
# //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
#/ \_// (_| | | |  __/  \  /\  /| |   <| |
#\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
#      |___/                              
#      Tutorial Framework
#      http://www.ogre3d.org/tikiwiki/
#-----------------------------------------------------------------------------
#*/
cmake_minimum_required(VERSION 2.6)
 
project(OgreApp)

if(WIN32)
	set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
	set(OGRE_SAMPLES_INCLUDEPATH
		$ENV{OGRE_HOME}/Samples/include
	)
endif(WIN32)
 
if(UNIX)
	set(CMAKE_CXX_FLAGS
		-fPIC
	)
	
	if(EXISTS "/usr/local/lib/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	  set(OGRE_SAMPLES_INCLUDEPATH "/home/ravenskrag/Code/GameDev/Libraries/ogre/Samples/Common/include") # We could just *assume* that developers uses this basepath : /usr/local

	elseif(EXISTS "/usr/lib/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	  set(OGRE_SAMPLES_INCLUDEPATH "/usr/share/OGRE/samples/Common/include/") # Otherwise, this one
	
	elseif(EXISTS "/usr/share/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules/;${CMAKE_MODULE_PATH}")
	  #set(OGRE_SAMPLES_INCLUDEPATH "/usr/share/OGRE/samples/Common/include/") # Otherwise, this one
	  set(OGRE_SAMPLES_INCLUDEPATH "/home/ravenskrag/Code/GameDev/Libraries/ogre/Samples/Common/include")
	else ()
	  message(SEND_ERROR "Failed to find module path.")
	endif(EXISTS "/usr/local/lib/OGRE")
endif(UNIX)
 
if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()
 
set(CMAKE_DEBUG_POSTFIX "_d")
 
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../")
 
find_package(OGRE REQUIRED)
 
#if(NOT "${OGRE_VERSION_NAME}" STREQUAL "Cthugha")
#  message(SEND_ERROR "You need Ogre 1.7 Cthugha to build this.")
#endif()
 
find_package(OIS REQUIRED)
 
if(NOT OIS_FOUND)
	message(SEND_ERROR "Failed to find OIS.")
endif()
 
# Find Boost
set(Boost_USE_STATIC_LIBS TRUE)


if (NOT OGRE_BUILD_PLATFORM_IPHONE)
	if (WIN32 OR APPLE)
		set(Boost_USE_STATIC_LIBS TRUE)
	else ()
		# Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
		set(Boost_USE_STATIC_LIBS ${OGRE_STATIC})
	endif ()
	if (MINGW)
		# this is probably a bug in CMake: the boost find module tries to look for
		# boost libraries with name libboost_*, but CMake already prefixes library
		# search names with "lib". This is the workaround.
		set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")

		find_package(Boost COMPONENTS thread date_time program_options filesystem system REQUIRED)
		#set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
		include_directories(${Boost_INCLUDE_DIR})
	endif ()
	set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
	# Components that need linking (NB does not include header-only components like bind)
	set(OGRE_BOOST_COMPONENTS thread date_time)
	find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	if (NOT Boost_FOUND)
		# Try again with the other type of libs
		set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
		find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	endif()
	find_package(Boost QUIET)
 
	# Set up referencing of Boost
	include_directories(${Boost_INCLUDE_DIR})
	add_definitions(-DBOOST_ALL_NO_LIB)
	set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
endif()

 
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

 
set(CORE_HDRS
	./cpp_core/BaseApplication.h
	./cpp_core/GameApplication.h
	
	./cpp_core/OniNode.h
	
	./cpp_core/OniLight.h
	
	./cpp_core/OniModel.h
	./cpp_core/OniAnimation.h
	./cpp_core/OniAnimationTrack.h
	./cpp_core/OniAnimationBone.h
)

set(CORE_SRCS
	./cpp_core/BaseApplication.cpp
	./cpp_core/GameApplication.cpp
	
	./cpp_core/OniNode.cpp
	
	./cpp_core/OniLight.cpp
	
	./cpp_core/OniModel.cpp
	./cpp_core/OniAnimation.cpp
	./cpp_core/OniAnimationTrack.cpp
	./cpp_core/OniAnimationBone.cpp
)

set(INTERFACE_HDRS
	./cpp_interface/OgreInterface.h
	./cpp_interface/OgreInterfaceBase.h
	
	./cpp_interface/Window.h
	./cpp_interface/Camera.h
	
	./cpp_interface/Node.h
	
	./cpp_interface/Light.h
	
	./cpp_interface/Model.h
	./cpp_interface/Animation.h
	./cpp_interface/AnimationTrack.h
	./cpp_interface/AnimationBone.h
)

set(INTERFACE_SRCS
	./cpp_interface/OgreInterface.cpp
	
	./cpp_interface/Window.cpp
	./cpp_interface/Camera.cpp
	
	./cpp_interface/Node.cpp
	
	./cpp_interface/Light.cpp
	
	./cpp_interface/Model.cpp
	./cpp_interface/Animation.cpp
	./cpp_interface/AnimationTrack.cpp
	./cpp_interface/AnimationBone.cpp
)

include_directories( ${OIS_INCLUDE_DIRS}
	${OGRE_INCLUDE_DIRS}
	${OGRE_SAMPLES_INCLUDEPATH}
)
 
#add_executable(OgreApp WIN32 ${CORE_HDRS} ${CORE_SRCS})
 
#set_target_properties(OgreApp PROPERTIES DEBUG_POSTFIX _d)
 
#target_link_libraries(OgreApp ${OGRE_LIBRARIES} ${OIS_LIBRARIES})


# Create static library
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/lib)
add_library(OniBase STATIC ${CORE_HDRS} ${INTERFACE_HDRS} ${CORE_SRCS} ${INTERFACE_SRCS})
target_link_libraries(OniBase ${OGRE_LIBRARIES} ${OIS_LIBRARIES})

 
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/bin)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/media)

# Create folder for created libraries
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/lib)
 
# post-build copy for win32
#if(WIN32 AND NOT MINGW)
#	add_custom_command( TARGET OgreApp PRE_BUILD
#		COMMAND if not exist .\\dist\\bin mkdir .\\dist\\bin )
#	add_custom_command( TARGET OgreApp POST_BUILD
#		COMMAND copy \"$(TargetPath)\" .\\dist\\bin )
#endif(WIN32 AND NOT MINGW)

if(MINGW OR UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist/bin)
endif(MINGW OR UNIX)
 
if(WIN32) 
	#install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/Media
	#	DESTINATION ./
	#	CONFIGURATIONS Release RelWithDebInfo Debug
	#)
 
	#install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
	#	${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
	#	DESTINATION bin
	#	CONFIGURATIONS Release RelWithDebInfo
	#)
 
	#install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins_d.cfg
	#	${CMAKE_SOURCE_DIR}/dist/bin/resources_d.cfg
	#	DESTINATION bin
	#	CONFIGURATIONS Debug
	#)
 
        # NOTE: for the 1.7.1 sdk the OIS dll is called OIS.dll instead of libOIS.dll
        # so you'll have to change that to make it work with 1.7.1
	#install(FILES ${OGRE_PLUGIN_DIR_REL}/OgreMain.dll
	#	${OGRE_PLUGIN_DIR_REL}/RenderSystem_Direct3D9.dll
	#	${OGRE_PLUGIN_DIR_REL}/RenderSystem_GL.dll
	#	${OGRE_PLUGIN_DIR_REL}/libOIS.dll
	#	DESTINATION bin
	#	CONFIGURATIONS Release RelWithDebInfo
	#)
 
	#install(FILES ${OGRE_PLUGIN_DIR_DBG}/OgreMain_d.dll
	#	${OGRE_PLUGIN_DIR_DBG}/RenderSystem_Direct3D9_d.dll
	#	${OGRE_PLUGIN_DIR_DBG}/RenderSystem_GL_d.dll
	#	${OGRE_PLUGIN_DIR_DBG}/libOIS_d.dll
	#	DESTINATION bin
	#	CONFIGURATIONS Debug
	#)
 
   # as of sdk 1.7.2 we need to copy the boost dll's as well
   # because they're not linked statically (it worked with 1.7.1 though)
   #install(FILES ${Boost_DATE_TIME_LIBRARY_RELEASE}
   #   ${Boost_THREAD_LIBRARY_RELEASE}
   #   DESTINATION bin
   #   CONFIGURATIONS Release RelWithDebInfo
   #)
 
   #install(FILES ${Boost_DATE_TIME_LIBRARY_DEBUG}
   #   ${Boost_THREAD_LIBRARY_DEBUG}
   #   DESTINATION bin
   #   CONFIGURATIONS Debug
   #)
endif(WIN32)

if(UNIX)
 
	#install(TARGETS OgreApp
	#	RUNTIME DESTINATION bin
	#	CONFIGURATIONS All)
 
endif(UNIX)

install(TARGETS OniBase
 		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib

		CONFIGURATIONS Release)