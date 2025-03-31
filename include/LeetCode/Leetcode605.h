#ifndef __LEETCODE605_HPP__
#define __LEETCODE605_HPP__

#include <iostream>
#include <vector>
bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
  const int size = flowerbed.size();
  auto canPlace = [&](int i) {
    if (i % 2 == 0) {
      return i / 2;
    }
    return i / 2 + 1;
  };

  int canPlaceCount = 0;
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (flowerbed[i] == 0) {
      ++count;
      if (flowerbed[i + 1] == 0 && count >= 2) {
        ++canPlaceCount;
      } else {
        n -= canPlace(canPlaceCount);
        canPlaceCount = 0;
      }
    } else {
      continue;
    }
  }

  return n == 0;
}

#endif