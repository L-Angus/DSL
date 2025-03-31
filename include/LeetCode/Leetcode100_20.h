#ifndef __LEETCODE100_20_HPP__
#define __LEETCODE100_20_HPP__

/**
 * @brief 有效的括号
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 *
 */

#include <string>

using namespace std;
bool isValid(string s) {
  auto beg = s.begin();
  auto search = beg + 1;
  auto isLeft = [](char c) { return c == '(' || c == '{' || c == '['; };
  auto isMatch = [](char left, char right) {
    return (left == '(' && right == ')') || (left == '{' && right == '}') ||
           (left == '[' && right == ']');
  };
  auto isMatchPosition = [](auto left, auto right) {
    auto size = right - left - 1;
    return size % 2 == 0;
  };

  while (search != s.end()) {
    if (*search == *beg) {
      beg = search + 1;
      search = beg + 1;
      continue;
    } else {
      if (isLeft(*search) ||
          !(isMatch(*beg, *search) && isMatchPosition(beg, search))) {
        search++;
      } else {
        ++beg;
        search = beg + 1;
      }
    }
  }
}

#endif