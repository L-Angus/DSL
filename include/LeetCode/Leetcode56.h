#ifndef __LEETCODE56_HPP__
#define __LEETCODE56_HPP__

#include <iostream>
#include <string>
int lengthOfLastWord(std::string s) {
  if (s.empty()) {
    return 0;
  }
  auto beg = s.begin();
  std::string sample = "";
  std::string last_word;
  bool update = false;
  while (beg != s.end()) {
    if (*beg == ' ') {
      if (!update)
        last_word = sample;
      sample = "";
      update = true;
      ++beg;
    } else {
      if (update)
        update = false;
      sample += *beg;
      ++beg;
    }
  }
  if (beg == s.end() && sample.size() > 0 && !update) {
    last_word = sample;
  }
  return last_word.size();
}

#endif