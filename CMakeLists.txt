cmake_minimum_required(VERSION 3.28)
project(sd_1_lista)

set(CMAKE_CXX_STANDARD 20)

#find_package(Boost 1.87.0 COMPONENTS system filesystem REQUIRED)
#
#if(Boost_FOUND)
#
#    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
#
#    include_directories(${Boost_INCLUDE_DIRS})
#
#endif()

add_executable(sd_1_lista main.cpp
        ArrayList.cpp
        ArrayList.hpp
        DoublyLinkedList.hpp
        BaseList.hpp
        DoublyLinkedList.cpp
        TestGenerator.hpp
        Utility.hpp)
