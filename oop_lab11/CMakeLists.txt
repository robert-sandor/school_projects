cmake_minimum_required(VERSION 3.0)
project(oop_lab11)

set(warnings "-Wall -Wextra -Werror")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${warnings}")

# Locate Google CPP Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Locate Qt5
find_package(Qt5Widgets REQUIRED)


set(SOURCE_FILES main.cpp)
add_executable(main_app ${SOURCE_FILES} Ingredient.cpp Ingredient.h MainWindow.cpp MainWindow.h)
target_link_libraries(main_app Qt5::Widgets)

add_executable(tests test.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)