cmake_minimum_required(VERSION 3.4)

project(C++)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(hello ${SOURCE_FILES})