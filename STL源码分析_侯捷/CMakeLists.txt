cmake_minimum_required(VERSION 3.21)
project(STL_)

set(CMAKE_CXX_STANDARD 11)

add_executable(STL_ main.cpp 1_基础问题/01分析基础.cpp 1_基础问题/assist.h 2_allocator/test.cpp 2_allocator/jjalloc.h 03_迭代器/3_1_find.cpp 03_迭代器/3_2_1_auto_ptr.cpp 03_迭代器/3_2_2_mylist.h 03_迭代器/3_2_3_myList_test.cpp)
