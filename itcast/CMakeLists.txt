cmake_minimum_required(VERSION 3.17)
project(itcast)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(oop)
add_subdirectory(stl)

add_executable(itcast main.cpp)
add_executable(memory memory.cpp)
add_executable(reference reference.cpp)