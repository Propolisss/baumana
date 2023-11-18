cmake_minimum_required(VERSION 3.26)
project(laba_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(laba_6
        List.cpp
        List.hpp
        Node.cpp
        Node.h
        Source.cpp
)
