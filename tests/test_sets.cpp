#include "sets.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>

struct TestCase {
  std::vector<int> input;
  std::vector<std::set<int>> output;
};

std::vector<TestCase> test_cases{
    {{1, 2, 3},
    {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}},
    {{},
    {{}}},
    {{1, 2},
    {{1}, {2}, {1, 2}, {}  }}
};

TEST(Sets, power_set) {
  for (auto test_case : test_cases) {
    auto result = power_set(test_case.input);
    std::ranges::sort(result);
    std::ranges::sort(test_case.output);
    EXPECT_EQ(result, test_case.output);
  }
}
