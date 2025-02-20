#include <sys/_types/_u_int.h>
#include <utility>
#include <vector>

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
