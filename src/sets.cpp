#include "sets.h"
#include <set>
#include <vector>

std::vector<std::set<int>> power_set(std::vector<int> nums) {
  if (nums.size() <= 0) {
    return std::vector<std::set<int>>(1);
  }
  std::vector<std::set<int>> output{};
  auto sub_nums = std::vector(nums.begin() + 1, nums.end());
  auto sets = power_set(sub_nums);
  for (std::set<int> elem : sets) {
    output.push_back(elem);
    std::set<int> elem_with_first = elem;
    elem_with_first.insert(nums.at(0));
    output.push_back(elem_with_first);
  }
  return output;
}
