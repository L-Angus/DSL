#ifndef __LEETCODE100_49_HPP__
#define __LEETCODE100_49_HPP__

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 字母异位词分组
 * 给你一个字符串数组，请你将 字母异位词组合在一起。可以按任意顺序返回结果列表。
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 * @param strs
 * @return vector<vector<string>>
 */
vector<vector<string>> groupAnagrams(vector<string> &strs) {
  const auto &strs_size = strs.size();
  if (strs_size == 0 || strs_size == 1)
    return std::vector<std::vector<std::string>>{strs};
  std::unordered_map<std::string, std::vector<std::string>> group_anagrams;
  // 先对字符串进行排序
  for (const auto &str : strs) {
    auto str_copy = str;
    std::sort(str_copy.begin(), str_copy.end());
    if (group_anagrams.find(str_copy) == group_anagrams.end()) {
      group_anagrams[std::move(str_copy)] = std::vector<std::string>{str};
    } else {
      group_anagrams[std::move(str_copy)].emplace_back(str);
    }
  }
  std::vector<std::vector<std::string>> res;
  res.reserve(group_anagrams.size());
  for (const auto &[_, value] : group_anagrams) {
    res.emplace_back(value);
  }
  return res;
}

#endif