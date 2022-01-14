cmake_minimum_required(VERSION 3.0)
project(c)

set(CMAKE_CXX_STANDARD 14)

add_executable(c main.cpp linear_list/sequenceList.cpp linear_list/singleLinkedList.cpp linear_list/doubleLinkedList.cpp linear_list/circularLinkedList.cpp linear_list/staticLinkedList.cpp)
