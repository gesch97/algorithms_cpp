#include "simple_math.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int minimum(std::vector<int> elements) {
  int output = INT_MAX;
  for (int elem : elements) {
    if (elem < output) {
      output = elem;
    }
  }
  return output;
}

int sum(std::vector<int> nums) {
  int sum{0};
  for (int num : nums) {
    sum += num;
  }
  return sum;
}

double avarage(std::vector<int> nums) {
  int sum = 0;
  for (int num : nums) {
    sum += num;
  }
  return sum / nums.size();
}

double median(std::vector<int> nums) {
  std::sort(nums.begin(), nums.end());
  int len = nums.size();
  if (len < 1) {
    return 0;
  }
  if (nums.size() % 2 == 1) {
    return nums[len / 2];
  } else {
    return (nums[len / 2] + nums[(len / 2) - 1]) / 2.0;
  }
}
