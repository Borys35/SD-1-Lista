cmake_minimum_required(VERSION 3.26.4)
project(sd_1_lista)

set(CMAKE_CXX_STANDARD 20)

add_executable(sd_1_lista main.cpp
        ArrayList.cpp
        ArrayList.hpp
        DoublyLinkedList.hpp
        BaseList.hpp
        DoublyLinkedList.cpp
        SinglyLinkedList.h
        SinglyLinkedList.cpp
        Menu.h
        Menu.cpp
        TestGenerator.cpp
        TestGenerator.hpp
        Utility.hpp)