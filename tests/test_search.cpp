#include "search.h"
#include "gtest/gtest.h"
#include <string>
#include <sys/_types/_u_int.h>
#include <tuple>

TEST(TestSearch, BinarySearch) {
  std::vector<std::tuple<std::vector<int>, int, bool>> test_cases{
      {{}, 2, false},
      {{1, 2, 3}, 2, true},
      {{1, 2, 3}, 1, true},
      {{1, 2, 3}, 3, true},
      {{1, 2, 3, 10}, 1, true},
      {{1, 2, 3, 10}, 2, true},
      {{1, 2, 3, 10}, 3, true},
      {{1, 2, 3, 10}, 4, false},
      {{1, 2, 3, 10}, 10, true},
      {{1, 2, 3, 10}, 100, false},
      {{1, 2, 3}, 4, false}};
  for (u_int i = 0; i < test_cases.size(); i++) {
    auto test_case = test_cases.at(i);
    auto v_in = &std::get<0>(test_case);
    int target = std::get<1>(test_case);
    bool result = binary_search(*v_in, target);
    bool exp_result = std::get<2>(test_case);

    EXPECT_EQ(result, exp_result) << "test_pos: " << i << std::endl;
  }
}
