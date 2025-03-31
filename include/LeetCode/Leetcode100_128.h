#ifndef __LEETCODE100_128_HPP__
#define __LEETCODE100_128_HPP__

/**
 * @brief 最长连续序列
 *
 * 给定一个未排序的整数数组
 * nums，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。请你设计并实现时间复杂度为
 * O(n) 的算法解决此问题。
 *
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int longestConsecutive(std::vector<int> &nums) {
  if (nums.size() == 0 || nums.size() == 1)
    return nums.size();

  //   std::set<int> numSet{nums.begin(), nums.end()};
  std::sort(nums.begin(), nums.end());
  int longestConsecutiveSize = 0;
  int subsequenceSize = 1;
  auto beg = nums.begin();
  auto next = std::next(beg);

  while (next != nums.end()) {
    if (*next - *beg == 1) {
      ++subsequenceSize;
      if (std::next(next) == nums.end()) {
        longestConsecutiveSize =
            std::max(longestConsecutiveSize, subsequenceSize);
        return longestConsecutiveSize;
      }
      ++beg;
      ++next;
      continue;
    } else {
      if (*next == *beg) {
        ++beg;
        ++next;
        continue;
      }
      longestConsecutiveSize =
          std::max(longestConsecutiveSize, subsequenceSize);
      subsequenceSize = 1;

      if (std::next(next) == nums.end()) {
        return longestConsecutiveSize;
      }
      ++beg;
      ++next;
      continue;
    }
  }

  longestConsecutiveSize = std::max(longestConsecutiveSize, subsequenceSize);
  return longestConsecutiveSize;
}

#endif