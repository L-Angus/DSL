#ifndef __LEETCODE435_HPP__
#define __LEETCODE435_HPP__

#include <vector>
int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
  const int n = intervals.size();
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int> &a, const std::vector<int> &b) {
              return a[1] < b[1];
            });
  int ans = 0;
  int right = intervals[0][1];
  for (int i = 1; i < n; ++i) {
    if (intervals[i][0] < right) {
      ++ans;
    } else {
      right = intervals[i][1];
    }
  }
  return ans;
}

#endif