#include <iostream>
#include <string>
#include <vector>

#include "../include/LinkedList.h"
#include "../include/Tree.h"
int main() {
  std::cout << "Hello, World!" << std::endl;
  DoublyLinkedList<int> *double_list = new DoublyLinkedList<int>();
  double_list->print();
  double_list->append(1);
  double_list->print();
  double_list->append(2);
  double_list->print();
  double_list->prepend(10);
  double_list->prepend(20);
  double_list->print();

  double_list->insert(2, 0);
  double_list->print();

  double_list->insert(static_cast<size_t>(0), 30);
  double_list->print();
  double_list->insert(6, 3);
  double_list->print();

  double_list->remove(2);
  double_list->print();

  double_list->remove_front();
  double_list->print();
  double_list->remove_back();
  double_list->print();

  double_list->update(1, 100);
  double_list->print();

  auto findElement = double_list->find(3);
  std::cout << "findElement: " << findElement << std::endl;

  auto findElement1 = double_list->find(0);
  std::cout << "findElement1: " << findElement1 << std::endl;

  std::cout << "double_list->size(): " << double_list->Size() << std::endl;
  double_list->clear();
  std::cout << "double_list->size(): " << double_list->Size() << std::endl;
  double_list->print();

  return 0;
}
