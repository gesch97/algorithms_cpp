# Enable testing
enable_testing()

# Add the test executable
add_executable(MyTests
    test_minimum.cpp
    test_search.cpp
)

# Link the test executable with the library
target_link_libraries(MyTests PRIVATE Algorithms ${GTEST_LIBRARIES} pthread)

# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})
target_compile_options(MyTests PRIVATE -Wall -Wextra -Wpedantic -Werror)

# Add the tests to CTest
# add_test(NAME Test1 COMMAND MyTests)
# add_test(NAME Test2 COMMAND MyTests --gtest_filter=Test2)
# Add other tests here
