#include "sort.h"
#include "gtest/gtest.h"

TEST(TestSorting, bubble) {
  std::vector<std::tuple<std::vector<int>, std::vector<int>>> test_cases{
      {{}, {}},
      {{3, 2, 1, 4}, {1, 2, 3, 4}},
      {{4, 3, 2, 1, 4}, {1, 2, 3, 4, 4}},
      {{1, 2, 3, 4}, {1, 2, 3, 4}}};
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = bubble_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}

TEST(TestSorting, merge) {
  std::vector<std::tuple<std::vector<int>, std::vector<int>>> test_cases{
      {{}, {}},
      {{3, 2, 1, 4}, {1, 2, 3, 4}},
      {{4, 3, 2, 1, 4}, {1, 2, 3, 4, 4}},
      {{1, 2, 3, 4}, {1, 2, 3, 4}}};
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = merge_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}
