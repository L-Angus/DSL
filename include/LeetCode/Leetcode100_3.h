#ifndef __LEETCODE100_3_HPP__
#define __LEETCODE100_3_HPP__

/**
 * @brief 无重复字符的最长子串
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int lengthOfLongestSubstring(string s) {
  unordered_set<char> window;
  int maxLen = 0;
  int left = 0; // 窗口左边界

  for (int right = 0; right < s.size(); ++right) { // right是窗口右边界
    while (window.count(s[right])) {               // 如果遇到重复字符
      window.erase(s[left]); // 从左边开始移除字符
      left++;                // 左边界右移
    }
    window.insert(s[right]);                // 把新字符加入窗口
    maxLen = max(maxLen, right - left + 1); // 更新最大长度
  }

  return maxLen;
}
#endif