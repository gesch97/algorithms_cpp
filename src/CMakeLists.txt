add_library(Algorithms
    minimum.cpp
    search.cpp
    sort.cpp
)

add_executable(my_prog main.cpp)
target_link_libraries(my_prog Algorithms)

target_include_directories(Algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
