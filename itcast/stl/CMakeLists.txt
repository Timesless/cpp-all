cmake_minimum_required(VERSION 3.17)
project(stl)

set(CMAKE_CXX_STANDARD 14)

add_executable(stl main.cpp)
add_executable(vect vec.cpp)
add_executable(str str.cpp)
add_executable(deck deck.cpp)
add_executable(stack_queue stack_queue.cpp)
add_executable(linkedlist LinkedList.cpp)
add_executable(set_multiset set_multiset.cpp)
add_executable(func func.cpp)
add_executable(alg alg.cpp)
