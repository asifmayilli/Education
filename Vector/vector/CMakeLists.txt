cmake_minimum_required(VERSION 3.3)
project(Vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  vector.h vector.c main.c)
add_executable(Vector ${SOURCE_FILES})