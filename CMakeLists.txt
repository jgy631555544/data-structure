cmake_minimum_required(VERSION 3.0)
project(c)

set(CMAKE_CXX_STANDARD 14)


add_executable(ds_0_sequenceListStatic linearList/ds_0_sequenceListStatic.cpp)
add_executable(ds_1_sequenceListDynamic linearList/ds_1_sequenceListDynamic.cpp)
add_executable(ds_2_singleLinkedListHeadNode linearList/ds_2_singleLinkedListHeadNode.cpp)
add_executable(ds_3_singleLinkedList linearList/ds_3_singleLinkedList.cpp)
add_executable(ds_4_doubleLinkedList linearList/ds_4_doubleLinkedList.cpp)
add_executable(ds_5_circularLinkedList linearList/ds_5_circularLinkedList.cpp)
add_executable(ds_6_circularDoubleLinkedList linearList/ds_6_circularDoubleLinkedList.cpp)
add_executable(ds_7_staticLinkedList linearList/ds_7_staticLinkedList.cpp)
add_executable(ds_0_sequenceStack stackAndQueue/ds_0_sequenceStack.cpp)
add_executable(ds_1_shareSequenceStack stackAndQueue/ds_1_shareSequenceStack.cpp)
add_executable(ds_2_linkStack stackAndQueue/ds_2_linkStack.cpp)
add_executable(ds_3_circleSequenceStack stackAndQueue/ds_3_circleSequenceStack.cpp)
add_executable(ds_4_circleSequenceStack stackAndQueue/ds_4_circleSequenceStack.cpp)
add_executable(ds_5_circleSequenceStack stackAndQueue/ds_5_circleSequenceStack.cpp)
add_executable(ds_6_linkQueueWithHeadNode stackAndQueue/ds_6_linkQueueWithHeadNode.cpp)
add_executable(ds_7_linkQueue stackAndQueue/ds_7_linkQueue.cpp)
add_executable(ds_8_queueApplication stackAndQueue/ds_8_queueApplication.cpp)
add_executable(kmp string/kmp.cpp)