
#include "sort.h"
#include <cstddef>
#include <sys/_types/_u_int.h>
#include <utility>
#include <vector>

static std::vector<int> merge(std::vector<int> a, std::vector<int> b);

std::vector<int> bubble_sort(std::vector<int> nums) {
  int j{0};
  for (u_int max_i = nums.size(); max_i > 1; max_i--) {
    for (u_int i = 1; i < max_i; i++) {
      j = i - 1;
      if (nums.at(j) > nums.at(i)) {
        std::swap(nums.at(j), nums.at(i));
      }
    }
  }

  return nums;
}

std::vector<int> merge_sort(std::vector<int> nums) {
  const size_t nums_size = nums.size();
  if (nums_size <= 1) {
    return nums;
  }

  size_t mid_index = nums.size() / 2;
  std::vector<int> v_a(nums.begin(), nums.begin() + mid_index);
  std::vector<int> v_b(nums.begin() + mid_index, nums.end());
  return merge(merge_sort(v_a), merge_sort(v_b));
}

static std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
  int i{0}, j{0};
  std::vector<int> output{};
  for (;;) {

    if (a.at(i) >= b.at(j)) {
      output.push_back(b.at(j));
      j++;
    } else {
      output.push_back(a.at(i));
      i++;
    }

    if (i >= a.size()) {
      output.insert(output.end(), b.begin() + j, b.end());
      break;
    }
    if (j >= b.size()) {
      output.insert(output.end(), a.begin() + i, a.end());
      break;
    }
  }
  return output;
}
