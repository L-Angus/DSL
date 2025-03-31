#ifndef __HELPER_HPP__
#define __HELPER_HPP__

#include <iostream>
#include <vector>
void print_vector(std::vector<int> &v) {
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif