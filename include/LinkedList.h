#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include <iostream>

// 单链表

/**
 * 双链表 DoublyLinkedList
 * 双链表结点的组成：
 * 直接前驱 + 数据 + 直接后继
 * 通常实现带有虚拟头结点(dummyHead)和虚拟尾结点(dummyTail)的，双链表的操作实现会更容易。
 *
 * */

template <typename T> class DoublyListNode {
public:
  T data;
  DoublyListNode *prev;
  DoublyListNode *next;
  explicit DoublyListNode(T val = T())
      : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T> class DoublyLinkedList {
public:
  DoublyLinkedList()
      : dummyHead(new DoublyListNode<T>()), dummyTail(new DoublyListNode<T>()),
        size(0) {
    Init();
  }
  DoublyLinkedList(const DoublyLinkedList &other)
      : dummyHead(new DoublyListNode<T>()), dummyTail(new DoublyListNode<T>()),
        size(other.size) {
    Init();
    for (DoublyListNode<T> *cur = other.dummyHead->next; cur != other.dummyTail;
         cur = cur->next) {
      append(cur->data);
    }
  }
  DoublyLinkedList &operator=(const DoublyLinkedList &other) {
    if (this != other) {
      // 保存原来的虚拟节点
      DoublyListNode<T> *oldHead = dummyHead;
      DoublyListNode<T> *oldTail = dummyTail;
      // 清空原来的链表
      clear();
      // 复制 other 的元素到当前链表
      for (DoublyListNode<T> *cur = other.dummyHead->next;
           cur != other.dummyTail; cur = cur->next) {
        append(cur->data);
      }
      delete oldHead;
      delete oldTail;
    }
    return *this;
  }

  DoublyLinkedList(DoublyLinkedList &&other) noexcept
      : dummyHead(other.dummyHead), dummyTail(other.dummyTail),
        size(other.size) {
    other.dummyHead = new DoublyListNode<T>();
    other.dummyTail = new DoublyListNode<T>();
    other.Init();
  }

  DoublyLinkedList &operator=(DoublyLinkedList &&other) noexcept {}
  ~DoublyLinkedList() {
    clear();
    delete dummyHead;
    delete dummyTail;
  }
  // 增
  /** 尾插法
   * 1. 创建新结点
   * 2. dummyTail->prev 指向新结点
   * 3. newNode->prev 指向 dummyTail->prev
   * 4. newNode->next 指向 dummyTail
   * 5. dummyTail->prev->next 指向 newNode
   */
  void append(T val) { insert(dummyTail, val); }
  /** 头插法
   * 1. 创建新结点
   * 2. dummyHead->next 指向新结点
   * 3. 新结点的 prev 指向 dummyHead
   * 4. 新结点的 next 指向 原来的头结点
   * 5. 原来的头结点的 prev 指向 新结点
   */
  void prepend(T val) { insert(dummyHead->next, val); }

  void insert(size_t index, T val) {
    if (index < 0 || index > size) {
      throw std::runtime_error("index out of range");
    }
    DoublyListNode<T> *cur = dummyHead->next;
    for (size_t i = 0; i < index; ++i) {
      cur = cur->next;
    }
    insert(cur, val);
  }

  // 删
  void remove_front() { remove(dummyHead->next); }
  void remove_back() { remove(dummyTail->prev); }
  void remove(size_t index) {
    DoublyListNode<T> *toRemoveNode = getNode(index);
    remove(toRemoveNode);
  }

  // 改
  void update(size_t index, T val) {
    DoublyListNode<T> *toUpdateNode = getNode(index);
    toUpdateNode->data = val;
  }
  // 查
  T find(size_t index) {
    DoublyListNode<T> *toFindNode = getNode(index);
    return toFindNode->data;
  };
  void print() {
    if (size == 0) {
      std::cout << "DoublyLinkedList is Empty: []" << std::endl;
      return;
    }
    DoublyListNode<T> *cur = dummyHead->next;
    std::cout << "Print DoublyLinkedList: [";
    int i = 0;
    while (cur != dummyTail) {
      if (i++ != 0)
        std::cout << ", ";
      std::cout << cur->data;
      cur = cur->next;
    }
    std::cout << "]" << std::endl;
  }

  size_t Size() const { return size; }

  void clear() {
    DoublyListNode<T> *cur = dummyHead->next;
    while (cur != dummyTail) {
      DoublyListNode<T> *toDeleteNode = cur;
      cur = cur->next;
      delete toDeleteNode;
    }
    Init();
  }

private:
  void Init() {
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    size = 0;
  }
  void insert(DoublyListNode<T> *pos, T val) {
    if (pos == nullptr || pos == dummyHead)
      return;
    // step 1-3
    DoublyListNode<T> *newNode = new DoublyListNode<T>(val);
    newNode->prev = pos->prev;
    pos->prev->next = newNode;
    newNode->next = pos;
    pos->prev = newNode;
    ++size;
  }

  void remove(DoublyListNode<T> *pos) {
    if (pos == nullptr || pos == dummyHead || pos == dummyTail)
      return;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    --size;
  }

  DoublyListNode<T> *getNode(size_t index) {
    if (index < 0 || index >= size) {
      throw std::runtime_error("index out of range");
    }
    DoublyListNode<T> *cur = dummyHead->next;
    for (size_t i = 0; i < index; i++) {
      cur = cur->next;
    }
    return cur;
  }

private:
  DoublyListNode<T> *dummyHead;
  DoublyListNode<T> *dummyTail;
  size_t size;
};

#endif