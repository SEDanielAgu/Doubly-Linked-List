cmake_minimum_required(VERSION 3.16)
project(linked_list_sample)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(linked_list_sample
        main.cpp
        LinkedListItem.cpp
        LinkedList.cpp LinkedList.h LinkedListItem.h LinkedListException.h LinkedList.cpp LinkedListItem.cpp)
