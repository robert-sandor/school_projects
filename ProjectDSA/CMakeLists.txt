cmake_minimum_required(VERSION 3.2)
project(ProjectDSA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Werror")

set(SOURCE_FILES main.cpp)
add_executable(ProjectDSA ${SOURCE_FILES} abstract_data_types.h SortedListDV.h SortedListRBT.h Balloon.h)