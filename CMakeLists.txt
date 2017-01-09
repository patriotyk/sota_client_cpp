##
# cmake Makefile for the sota_client_cpp
#
# Copyright (c) 2016 Advanced Telematic Systems GmbH
#
# Author: Moritz Klinger - mklinger@embeddeers.com
#

# define the minimum cmake version that is required
cmake_minimum_required (VERSION 2.6)

# define a project name
PROJECT(sota_client_cpp)

# optionally disable treating warnings as errors
option(WARNING_AS_ERROR "Treat warnings as errors" ON)

# enable code coverage
option(BUILD_WITH_CODE_COVERAGE "Enable gcov code coverage" OFF)

# set build type to Debug or Release here
set(CMAKE_BUILD_TYPE Debug)


OPTION(BUILD_WITH_DBUS_GATEWAY "Set to ON to compile with dbus gateway support" OFF)
message(STATUS "BUILD_WITH_DBUS_GATEWAY is set to value: ${BUILD_WITH_DBUS_GATEWAY}")
if(BUILD_WITH_DBUS_GATEWAY)

add_definitions(-DWITH_DBUS)


include(ExternalProject)

ExternalProject_Add(libdbus
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/dbus-1.9.0
    CONFIGURE_COMMAND  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/dbus-1.9.0/configure --prefix=${CMAKE_CURRENT_SOURCE_DIR}/libdbus_build --with-systemdsystemunitdir=${CMAKE_CURRENT_SOURCE_DIR}/libdbus_build/lib/systemd
    BUILD_COMMAND ${MAKE}
    BUILD_IN_SOURCE 1)

ExternalProject_Add(commonapi
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/common-api-runtime
    CONFIGURE_COMMAND cmake ${CMAKE_CURRENT_SOURCE_DIR}/third_party/common-api-runtime/ -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/commonapi_install
    BUILD_COMMAND ${MAKE}
    BUILD_IN_SOURCE 1)

ExternalProject_Add(dbusapi
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/common-api-dbus-runtime
    CONFIGURE_COMMAND PKG_CONFIG_PATH=${CMAKE_CURRENT_SOURCE_DIR}/libdbus_build/lib/pkgconfig cmake ${CMAKE_CURRENT_SOURCE_DIR}/third_party/common-api-dbus-runtime/  -DUSE_INSTALLED_COMMONAPI=OFF  -DUSE_INSTALLED_DBUS=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/dbusapi_install
    BUILD_COMMAND ${MAKE}
    BUILD_IN_SOURCE 1)

endif(BUILD_WITH_DBUS_GATEWAY)

#add_subdirectory("src")
# FIXME temporary use include because of bugs with coverage
include("src/CMakeLists.txt")
include("tests/CMakeLists.txt")
