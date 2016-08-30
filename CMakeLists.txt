cmake_minimum_required(VERSION 3.0)

project(perceived_brightness CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ggdb3")

#Bring the headers into the project
include_directories(include)

option(BUILD_TESTS "Build test programs" OFF)

# Unit tests section
enable_testing()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_subdirectory(main)
add_subdirectory(libcolor)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif (BUILD_TESTS)
