cmake_minimum_required(VERSION 3.2)
project(oop_lab11)

set(warnings "-Wall -Wextra -Werror")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${warnings}")

# Locate Google CPP Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(oop_lab11 ${SOURCE_FILES} Ingredient.cpp Ingredient.h)

add_executable(oop_lab11_test test.cpp)
target_link_libraries(oop_lab11_test ${GTEST_LIBRARIES} pthread)