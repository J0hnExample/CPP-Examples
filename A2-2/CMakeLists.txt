cmake_minimum_required(VERSION 3.2)

project(A2_1)

set(CMAKE_CXX_STANDARD "14")

# Add trackmymoves.cpp to the list of source files
set(SOURCE_FILES main.cpp payload.cpp test21.cpp test22.cpp trackmymoves.cpp)

add_executable(test_it ${SOURCE_FILES})
