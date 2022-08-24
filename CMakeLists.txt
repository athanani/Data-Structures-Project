cmake_minimum_required(VERSION 3.17)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructures main.cpp Unordered_Array.cpp Unordered_Array.h Ordered_Array.cpp Ordered_Array.h AVLBinaryTree.cpp AVLBinaryTree.h Node.h BinaryTree.cpp BinaryTree.h HashTable.cpp HashTable.h Pair.h)