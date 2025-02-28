#include <iostream>
#include <string>
#include <vector>

#include "../include/LinkedList.h"
#include "../include/MySTL/Find.hpp"
#include "../include/MySTL/Vector.hpp"
#include "../include/MySTL/overloading.hpp"
#include "../include/Tree.h"
int main() {
  // std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // auto it = Find(nums.begin(), nums.end(), 5);
  // std::cout << (it != nums.end()) << std::endl;

  // int ia[5] = {0, 1, 2, 3, 4};
  // Vector<int> x;
  // Vector<int>::iterator ite = nullptr;
  // x.insert(ite, ia, ia + 5); // insert()

  // INT I(5);
  // std::cout << I << std::endl;
  // std::cout << ++I << std::endl;
  // std::cout << I++ << std::endl;
  // std::cout << --I << std::endl;
  // std::cout << I-- << std::endl;
  // std::cout << *I << std::endl;
  Plus<int> plusobj;
  Minus<int> minusobj;
  std::cout << plusobj(3, 5) << std::endl;
  std::cout << minusobj(3, 5) << std::endl;

  std::cout << Plus<int>()(43, 50) << std::endl;
  std::cout << Minus<int>()(43, 50) << std::endl;

  return 0;
}
