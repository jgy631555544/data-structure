cmake_minimum_required(VERSION 3.0)
project(c)

set(CMAKE_CXX_STANDARD 14)

add_executable(sequenceList linear_list/sequenceList.cpp)
add_executable(singleLinkedList linear_list/singleLinkedList.cpp)
add_executable(staticLinkedList linear_list/staticLinkedList.cpp)
add_executable(singleLinkedListHeadNode linear_list/singleLinkedListHeadNode.cpp)
add_executable(doubleLinkedList linear_list/doubleLinkedList.cpp)
add_executable(circularLinkedList linear_list/circularLinkedList.cpp)