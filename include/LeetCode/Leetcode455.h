#ifndef __LEETCODE455_HPP__
#define __LEETCODE455_HPP__

#include "helper.hpp"
#include <unordered_set>
#include <vector>
int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());
  int child_i = 0, cookie_i = 0;
  int children_size = g.size(), cookie_size = s.size();
  while (child_i < children_size && cookie_i < cookie_size) {
    if (g[child_i] <= s[cookie_i]) {
      ++child_i;
    }
    ++cookie_i;
  }

  return child_i;
}

#endif