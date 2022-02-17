cmake_minimum_required(VERSION 3.0)
project(c)

set(CMAKE_CXX_STANDARD 14)

add_executable(sequenceListStatic linear_list/sequenceListStatic.cpp)
add_executable(sequenceListDynamic linear_list/sequenceListDynamic.cpp)