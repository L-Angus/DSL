#ifndef __LEETCODE100_11_HPP__
#define __LEETCODE100_11_HPP__

#include <iostream>
#include <vector>
/**
 * @brief 盛最多水的容器
 *
 */
using namespace std;
int maxArea(const std::vector<int> &height) {
  if (height.size() < 2)
    return 0;
  auto left = height.begin();
  auto right = height.end() - 1;
  int area = 0;
  while (left < right) {
    auto hgt = std::min(*left, *right);
    auto length = std::distance(left, right);
    auto curArea = hgt * length;
    if (curArea > area) {
      area = std::move(curArea);
    }
    if (hgt == *left) {
      ++left;
    } else {
      --right;
    }
  }
  return area;
}

#endif