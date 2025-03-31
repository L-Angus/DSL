#ifndef __LEETCODE26_HPP__
#define __LEETCODE26_HPP__

#include <vector>
int removeDuplicates(std::vector<int> &nums) {
  if (nums.size() == 0)
    return 0;
  auto beg = nums.begin();
  auto next = beg + 1;
  while (next != nums.end()) {
    if (*next == *beg) {
      ++next;
      continue;
    } else {
      ++beg;
      *beg = *next;
      ++next;
    }
  }
  return ++beg - nums.begin();
}

#endif