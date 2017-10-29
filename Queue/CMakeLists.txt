cmake_minimum_required(VERSION 3.3)
project(Queue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Queue.cpp QueueArray.cpp)
add_executable(Queue ${SOURCE_FILES})