add_executable(MyTests
    test_simple_math.cpp
    test_search.cpp
    test_sort.cpp
)

target_link_libraries(MyTests PRIVATE Algorithms ${GTEST_LIBRARIES})
target_compile_options(MyTests PRIVATE -Wall -Wextra -Wpedantic -Werror)
