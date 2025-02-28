#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
using namespace std;

class alloc {};
template <typename T, typename Alloc = alloc> class Vector {
public:
  typedef T value_type;         // 元素类型
  typedef value_type *iterator; // 迭代器类型
  template <class I> void insert(iterator pos, I first, I last) {
    cout << "insert" << endl;
  }
};

#endif