cmake_minimum_required(VERSION 3.6)
project(MyQueue)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

set(SOURCE_FILES
        main.cpp
        MyQueue.cpp
        MyQueue.h
    )

add_executable(
        MyQueue
        ${SOURCE_FILES})
