#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include <iostream>

template <typename T> struct ListNode {
  T val;
  ListNode *next;
  ListNode() : val(T()), next(nullptr) {}
  ListNode(T x) : val(x), next(nullptr) {}
};

/**
 * @brief 单链表
 *
 * @tparam T
 */

template <typename T> class LinkedList {
public:
  LinkedList() : head(nullptr), tail(nullptr), count(0) {}
  explicit LinkedList(T x) : head(new ListNode<T>(x)), tail(head), count(1) {}
  ~LinkedList() {
    ListNode<T> *curr = head;
    while (curr) {
      ListNode<T> *next = curr->next;
      delete curr;
      curr = next;
    }
    head = tail = nullptr;
    count = 0;
  }
  void push_front(T x) {
    if (!head) {
      head = new ListNode<T>(x);
      tail = head;
    } else {
      ListNode<T> *node = new ListNode<T>(x);
      node->next = head;
      head = node;
    }
    ++count;
  }
  void push_back(T x) {
    if (!head) {
      head = new ListNode<T>(x);
      tail = head;
    } else {
      tail->next = new ListNode<T>(x);
      tail = tail->next;
    }
    ++count;
  }
  void remove(T x) {
    ListNode<T> *curr = head;
    ListNode<T> *prev = nullptr;
    while (curr) {
      if (curr->val == x) {
        if (!prev) {
          head = head->next;
          curr->next = nullptr;
        } else {
          prev->next = curr->next;
          curr->next = nullptr;
        }
        delete curr;
        --count;
        return;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
  }
  size_t size() const { return count; }
  bool empty() const { return count == 0; }
  bool contains(T x) const {
    ListNode<T> *curr = head;
    while (curr) {
      if (curr->val == x)
        return true;
      curr = curr->next;
    }
    return false;
  }
  void print() const {
    ListNode<T> *curr = head;
    std::cout << "LinkedList: \n";
    while (curr->next) {
      std::cout << curr->val << " ";
      curr = curr->next;
    }
    std::cout << curr->val << std::endl;
    delete curr;
  }

private:
  ListNode<T> *head;
  ListNode<T> *tail;
  size_t count;
};

#endif