# Standard setup
set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required (VERSION 2.8)
project (hello-lib CXX C)

add_definitions (-DUSE_WEBSOCKET -DNO_SSL)

# Includes
include_directories (${hello-lib_SOURCE_DIR})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/main
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../arch-common/main
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../arch-common/third_party
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../tmp
  )

file(GLOB_RECURSE CommonSources ../../../arch-common/main/*.cpp )
set(CommonSources
    ${CommonSources}
    ../../../arch-common/third_party/civetweb/CivetServer.cpp
    ../../../arch-common/third_party/civetweb/civetweb.c)

#file( GLOB_RECURSE MacSources main/*.cpp )

# Source files
set (SRC
  ${CommonSources}
	HelloWorld.cpp
	HelloIOS.mm
)

# Headers
set (HDR
	HelloWorld.h
	HelloIOS.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-abi-version=2 -fobjc-arc -std=gnu++11 -stdlib=libc++ -isysroot ${CMAKE_OSX_SYSROOT}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fobjc-abi-version=2 -fobjc-arc -isysroot ${CMAKE_OSX_SYSROOT}")

IF (${SIMULATOR})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mios-simulator-version-min=6.0")
ENDIF()

# Library
add_library (hello-lib STATIC ${SRC} ${HDR})
set_xcode_property (hello-lib GCC_GENERATE_DEBUGGING_SYMBOLS YES)

# Installation
set (CMAKE_INSTALL_PREFIX "${hello-lib_SOURCE_DIR}/../hello-app/hello-app")
install (TARGETS hello-lib DESTINATION .)
install (FILES HelloIOS.h DESTINATION .)
