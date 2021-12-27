cmake_minimum_required(VERSION 3.17)
project(lab1_s3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(gtest/googletest)

include_directories(gtest/googletest/googletest/include)
add_executable(lab1_s3 LInkedList.h Sequence.h LinkedListSequence.h DynamicArray.h ArraySequence.h main.cpp ISorter.h tests.cpp menu.h)
target_link_libraries(lab1_s3 gtest)