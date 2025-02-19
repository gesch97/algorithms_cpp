#include <stdio.h>
#include <sys/_types/_u_int.h>
#include <vector>
bool binary_search(std::vector<int> nums, int target) {
  if (nums.size() < 1) {
    return false;
  }

  u_int low{0};
  u_int high = nums.size() - 1;
  u_int mid;

  while (high >= low) {
    mid = (high + low) / 2;

    if (nums.at(mid) == target) {
      return true;
    }
    if (nums.at(mid) < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
