#include "minimum.h"
#include <gtest/gtest.h>
#include <utility>
#include <vector>

TEST(Test_algorithms, Minimum) {
  std::vector<std::pair<std::vector<int>, int>> test_cases{
      {{1, 2, 3}, 1}, {{-10000, 10, 0, 0}, -10000}};
  for (auto test_case : test_cases) {
    int res = minimum(test_case.first);
    EXPECT_EQ(res, test_case.second);
  }
}
TEST(Test_algorithms, Sum) {
  std::vector<std::pair<std::vector<int>, int>> test_cases{
      {{1, 2, 3}, 6},
      {{0}, 0},
    {{-10000, 10, 0, 0}, -9990}};
  for (auto test_case : test_cases) {
    int res = sum(test_case.first);
    EXPECT_EQ(res, test_case.second);
  }
}

TEST(Test_algorithms, Avarage) {
  std::vector<std::pair<std::vector<int>, double>> test_cases{
      {{1, 2, 3}, 2.0},
      {{0}, 0.0},
      {{10,10}, 10.0}};
  for (auto test_case : test_cases) {
    int res = avarage(test_case.first);
    EXPECT_EQ(res, test_case.second);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
