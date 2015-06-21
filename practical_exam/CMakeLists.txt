cmake_minimum_required(VERSION 3.2)
project(practical_exam)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# find Qt5 libraries
set(CMAKE_PREFIX_PATH "/opt/Qt/5.4/gcc_64")
find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES main.cpp)
add_executable(main_app ${SOURCE_FILES} Bookmark.cpp Bookmark.h bookmark_validator.h BookmarkRepository.cpp BookmarkRepository.h)
target_link_libraries(main_app Qt5::Widgets)