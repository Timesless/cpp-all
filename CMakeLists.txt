cmake_minimum_required(VERSION 3.17)
project(cpp_all)

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(houjie)
add_subdirectory(wengkai)
add_subdirectory(itcast)

add_executable(cpp_all main.cpp)