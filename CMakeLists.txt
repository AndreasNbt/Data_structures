cmake_minimum_required(VERSION 3.17)
project(Data_structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_structures
        Data_structures/array.cpp
        Data_structures/array.h
        Data_structures/sorted_array.cpp
        Data_structures/sorted_array.h
        Data_structures/BinaryTree.cpp
        Data_structures/BinaryTree.h
        Data_structures/HashTable.cpp
        Data_structures/HashTable.h
        Data_structures/AVLTree.cpp
        Data_structures/AVLTree.h
        main.cpp)
