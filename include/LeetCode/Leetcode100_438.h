#ifndef __LEETCODE100_438_HPP__
#define __LEETCODE100_438_HPP__

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
std::vector<int> findAnagrams(std::string s, std::string p) {
  auto size = p.size();
  std::set<char> set(p.begin(), p.end());

  std::vector<int> res;
  for (int i = 0; i < s.size(); ++i) {
    auto sub = s.substr(i, size);
    if (sub.size() != size) {
      continue;
    }
  }
  return res;
}

#endif