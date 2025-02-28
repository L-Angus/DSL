#ifndef __OVERLOADING_HPP__
#define __OVERLOADING_HPP__

#include <iostream>
using namespace std;

class INT {
public:
  friend ostream &operator<<(ostream &os, const INT &i);

  INT(int i = 0) : m_i(i) {}
  INT &operator++() {
    ++(this->m_i);
    return *this;
  }
  INT operator++(int) {
    INT tmp = *this;
    ++(*this);
    return tmp;
  }
  INT &operator--() {
    --(this->m_i);
    return *this;
  }
  INT operator--(int) {
    INT tmp = *this;
    --(*this);
    return tmp;
  }
  int &operator*() { return (int &)this->m_i; }

private:
  int m_i;
};

ostream &operator<<(ostream &os, const INT &i) {
  os << i.m_i;
  return os;
}

template <typename T> struct Plus {
  T operator()(const T &a, const T &b) const { return a + b; }
};

template <typename T> struct Minus {
  T operator()(const T &a, const T &b) const { return a - b; }
};

#endif