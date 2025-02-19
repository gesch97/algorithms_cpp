# Create a library from the source files in the src directory
add_library(Algorithms
    minimum.cpp
    search.cpp
)

# Specify the include directories for the library
target_include_directories(Algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
