cmake_minimum_required(VERSION 3.28)
project(arrayclass)

set(CMAKE_CXX_STANDARD 17)

add_executable(arrayclass main.cpp
        array.cpp
        array.h
        tests.cpp
        tests.h
        queuearray.cpp
        queuearray.h
        smartarray.cpp
        smartarray.h
        linkedlist.cpp
        linkedlist.h
        linkedlist_template.h)
