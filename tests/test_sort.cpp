#include "sort.h"
#include "gtest/gtest.h"

static const std::vector<std::tuple<std::vector<int>, std::vector<int>>>
    test_cases{{{1, 4}, {1, 4}},
               {{3, 2, 1, 4}, {1, 2, 3, 4}},
               {{3, 2, -10, 1, 4}, {-10, 1, 2, 3, 4}},
               {{}, {}},
               {{4, 3, 2, 1, 4}, {1, 2, 3, 4, 4}},
               {{1, 2}, {1, 2}},
               {{1, 1}, {1, 1}},
               {{1, 1, 1}, {1, 1, 1}},
               {{2, 1}, {1, 2}},
               {{1, 2, 3}, {1, 2, 3}},
               {{1, 2, 3, 4}, {1, 2, 3, 4}}};

TEST(TestSorting, bubble) {
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = bubble_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}

TEST(TestSorting, merge) {
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = merge_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}

TEST(TestSorting, insertion) {
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = insertion_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}

TEST(TestSorting, quick) {
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = quick_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}
TEST(TestSorting, selection) {
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    auto result = selection_sort(*v_in);
    auto exp_result = std::get<1>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}
