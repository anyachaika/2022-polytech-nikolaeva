cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(queue10)

set(CMAKE_CXX_STANDARD 17)

add_executable(queue10 Queue.h testqueue.cpp)
