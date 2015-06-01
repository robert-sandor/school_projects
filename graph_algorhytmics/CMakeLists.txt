cmake_minimum_required(VERSION 3.2)
project(graph_algorhytmics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(graph_algorhytmics ${SOURCE_FILES} Graph.cpp Graph.h)