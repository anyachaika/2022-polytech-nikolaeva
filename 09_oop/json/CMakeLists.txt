cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(json09)

set(CMAKE_CXX_STANDARD 17)

add_executable(json09 Json.h test_json.cpp)
