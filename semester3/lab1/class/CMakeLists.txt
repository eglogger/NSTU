cmake_minimum_required(VERSION 3.28)
project(class)

set(CMAKE_CXX_STANDARD 17)

add_executable(class array.cpp
        array.h
        tests.h)
