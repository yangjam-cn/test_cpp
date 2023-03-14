cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

project(StudyCpp LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -fPIC -O0")

message("c++ flags: ${CMAKE_CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

option(BUILD_VS "build vc_cpp" false)

set(BUILD_VS true)

if (BUILD_VS)
    add_subdirectory(vs_cpp)
endif()