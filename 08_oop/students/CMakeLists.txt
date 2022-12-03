cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(students08)

set(CMAKE_CXX_STANDARD 17)

include(doctest.cmake)
add_executable(students08 test_student.cpp doctest.h Student.cpp Student.h StudentList.cpp StudentList.h)
target_link_libraries(students08 PRIVATE doctest)
