#include "minimum.h"
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

int sum(std::vector<int> nums){
  int sum{0};
  for (int num : nums){
    sum += num;
  }
  return sum;

}
