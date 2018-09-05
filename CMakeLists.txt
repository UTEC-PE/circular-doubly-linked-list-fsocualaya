cmake_minimum_required(VERSION 3.10)
project(circular_doubly_linked_list_fsocualaya)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(circular_doubly_linked_list_fsocualaya
        iterator.h
        list.h
        main.cpp
        node.h)
