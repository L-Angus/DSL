#ifndef __LEETCODE100_35_HPP__
#define __LEETCODE100_35_HPP__

#include <vector>

/**
 * @brief 搜索插入位置
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 请必须使用时间复杂度为 O(log n) 的算法。
 */
using namespace std;
int searchInsert(vector<int> &nums, int target) {
  auto hit = std::lower_bound(nums.begin(), nums.end(), target);
  if (hit == nums.end()) {
    return nums.size();
  }
  return hit - nums.begin();
}

#endif