cmake_minimum_required(VERSION 2.8)
project(SDA_Project_New)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(SDA_Project_New ${SOURCE_FILES} adt.h sorted_list_dv.h sorted_list_rbt.h Balloon.cpp Balloon.h)