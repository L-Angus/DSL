#ifndef __LEETCODE100_238_HPP__
#define __LEETCODE100_238_HPP__

/**
 * @brief 移动零
 *
 * 给定一个数组nums，编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序。
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 *
 */

#include <iostream>
#include <vector>

using namespace std;
void moveZeroes(vector<int> &nums) {
  if (nums.size() == 0 || nums.size() == 1)
    return;
  auto beg = nums.begin();
  auto next = beg + 1;
  while (next != nums.end()) {
    if (*beg == 0) {
      if (*next != 0) {
        *beg = *next;
        *next = 0;
        beg++;
      } else {
        next++;
      }
    } else {
      beg++;
      next++;
    }
  }
}

#endif