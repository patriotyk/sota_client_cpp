# set symbols used when compiling
add_definitions(-DBOOST_LOG_DYN_LINK=1)

# find all required libraries
find_package(Boost COMPONENTS system thread program_options log log_setup regex REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(LIBCURL REQUIRED libcurl)
pkg_search_module(LIBOPENSSL REQUIRED libssl)
pkg_search_module(SYSTEMD libsystemd)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
include_directories(
    src/dbusgateway/
)


# configure libraries
set(LINK_LIBS libpthread.so
              ${Boost_SYSTEM_LIBRARY}
              ${Boost_THREAD_LIBRARY}
              ${Boost_LOG_LIBRARIES}
              ${Boost_LOG_SETUP_LIBRARIES}
              ${Boost_PROGRAM_OPTIONS_LIBRARY}
              ${Boost_REGEX_LIBRARY}
              ${LIBCURL_LIBRARIES}
              ${SYSTEMD_LIBRARIES})


# set source files excluded main for using the list for the test target
set(SOURCES third_party/jsoncpp/jsoncpp.cpp
            src/logger.cc
            src/httpclient.cc
            src/sotahttpclient.cc
            src/interpreter.cc
            src/config.cc
            src/events.cc
            src/commands.cc
            src/types.cc
            src/main.cc
            src/dbusgateway/HelloWorldStubImpl.cpp
            src/dbusgateway/v1/commonapi/HelloWorldStubDefault
            src/dbusgateway/v1/commonapi/HelloWorldDBusDeployment
            src/dbusgateway/v1/commonapi/HelloWorldDBusStubAdapter)

set(HEADERS src/logger.h
            src/config.h
            src/interpreter.h
            src/httpclient.h
            src/sotahttpclient.h
            src/events.h
            src/commands.h
            src/types.h)

set_property(SOURCE third_party/jsoncpp/jsoncpp.cpp APPEND_STRING PROPERTY COMPILE_FLAGS " -w")

include_directories(third_party/jsoncpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdbus_build/include/dbus-1.0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdbus_build/lib/dbus-1.0/include/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/commonapi_install/include/CommonAPI-3.1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dbusapi_install/include/CommonAPI-3.1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dbusapi_install/include)
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/libdbus_build/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/commonapi_install/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/dbusapi_install/lib
)


# set output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY target/)

# set the name of the executable
add_executable(sota_client ${SOURCES})

# define libraries for the target
target_link_libraries(sota_client ${LINK_LIBS} CommonAPI CommonAPI-DBus dbus-1)
add_dependencies(sota_client dbusapi)
add_dependencies(dbusapi commonapi libdbus)


add_executable(HelloWorldClient
    src/dbusgateway/HelloWorldClient.cpp
    src/dbusgateway/v1/commonapi/HelloWorldDBusProxy.cpp
    src/dbusgateway/v1/commonapi/HelloWorldDBusDeployment
)
target_link_libraries(HelloWorldClient CommonAPI CommonAPI-DBus dbus-1)


