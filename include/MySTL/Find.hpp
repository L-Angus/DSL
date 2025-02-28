#ifndef __FIND_HPP__
#define __FIND_HPP__

template <class InputIterator, class T>
InputIterator Find(InputIterator first, InputIterator last, const T &value) {
  while (first != last && *first != value)
    ++first;
  return first;
}

#endif