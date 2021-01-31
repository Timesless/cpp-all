cmake_minimum_required(VERSION 3.17)
project(oop)

set(CMAKE_CXX_STANDARD 14)


add_executable(oop main.cpp)
add_executable(op_overload op_overload.cpp)
add_executable(diamond diamond_extend.cpp)
add_executable(polymorphism polymorphism.cpp)
add_executable(file file.cpp)
add_executable(template template.cpp)
add_executable(array array.cpp)
add_executable(callback callback_func.cpp)