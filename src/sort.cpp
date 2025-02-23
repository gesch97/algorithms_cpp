
#include "sort.h"
#include <cstddef>
#include <sys/_types/_u_int.h>
#include <utility>
#include <vector>

static std::vector<int> merge(std::vector<int> a, std::vector<int> b);
static void quick_sort_recursive(std::vector<int> &nums, size_t from,
                                 size_t to);
static size_t partition(std::vector<int> &nums, size_t from, size_t to);

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

std::vector<int> insertion_sort(std::vector<int> nums) {
  size_t j{0};
  for (size_t i = 1; i < nums.size(); i++) {
    j = i;
    while (j >= 1 && nums.at(j) < nums.at(j - 1)) {
      std::swap(nums.at(j), nums.at(j - 1));
      j--;
    }
  }
  return nums;
}

std::vector<int> quick_sort(std::vector<int> nums) {
  const size_t nums_size = nums.size();
  if (nums_size <= 1) {
    return nums;
  }
  quick_sort_recursive(nums, 0, nums_size - 1);
  return nums;
}

static void quick_sort_recursive(std::vector<int> &nums, size_t from,
                                 size_t to) {
  if (from < to) {
    size_t mid_id = partition(nums, from, to);
    if (mid_id > 0) {
      quick_sort_recursive(nums, from, mid_id - 1);
    }
    quick_sort_recursive(nums, mid_id + 1, to);
  }
}

static size_t partition(std::vector<int> &nums, size_t from, size_t to) {
  int i = from;
  int pivot = nums.at(to);
  for (size_t j = i; j < to; j++) {
    auto j_val = nums.at(j);
    auto i_val = nums.at(i);
    if (nums.at(j) < pivot) {
      std::swap(nums.at(i), nums.at(j));
      i++;
    }
  }
  std::swap(nums.at(i), nums.at(to));
  return i;
}

std::vector<int> selection_sort(std::vector<int> nums) {
  size_t smallest_idx{0};
  for (size_t i = 0; i < nums.size(); i++) {
    smallest_idx = i;
    for (size_t j = smallest_idx; j < nums.size(); j++) {
      if (nums.at(j) < nums.at(smallest_idx)) {
        smallest_idx = j;
      }
    }
    std::swap(nums.at(i), nums.at(smallest_idx));
  }
  return nums;
}
