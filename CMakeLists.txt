cmake_minimum_required(VERSION 3.30)
project(Algritms_cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(src)

# Add the tests directory
add_subdirectory(tests)
