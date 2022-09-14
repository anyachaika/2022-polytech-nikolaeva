cmake_minimum_required(VERSION 3.16)
project(compiler02)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler02.out hello_world.cpp func.cpp func.h)
