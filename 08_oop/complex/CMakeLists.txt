cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(complex08)

set(CMAKE_CXX_STANDARD 17)

include(doctest.cmake)
add_executable(complex08 test_complex.cpp doctest.h Complex.cpp Complex.h)
target_link_libraries(complex08 PRIVATE doctest)
