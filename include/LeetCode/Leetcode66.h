#ifndef __LEETCODE66_HPP__
#define __LEETCODE66_HPP__

#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int> &digits) {
  auto is9 = [](int num) { return num == 9; };
  auto Contins9 = [&is9](std::vector<int> &nums) {
    auto begin = nums.rbegin();
    auto end = nums.rend();
    while (begin != end) {
      if (is9(*begin)) {
        *begin = 0;
        ++begin;
      } else {
        *begin += 1;
        return;
      }
    }
    nums.insert(nums.begin(), 1);
  };

  if (is9(digits.back())) {
    Contins9(digits);
  } else {
    digits.back() += 1;
  }
  return digits;
}

void test66() {
  std::vector<int> digits1 = {1, 2, 3};
  auto res = plusOne(digits1);
  for (auto i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> digits2 = {4, 3, 2, 1};
  auto res2 = plusOne(digits2);
  for (auto i : res2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::vector<int> digits3 = {9};
  auto res3 = plusOne(digits3);
  for (auto i : res3) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> digits4 = {9, 9, 9};
  auto res4 = plusOne(digits4);
  for (auto i : res4) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> digits5 = {8, 9, 9, 9};
  auto res5 = plusOne(digits5);
  for (auto i : res5) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

#endif