#include <iostream>
#include <string>

#include "../include/LinkedList.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  LinkedList<std::string> *myList = new LinkedList<std::string>("赵");

  myList->push_back("钱");
  myList->push_back("孙");
  myList->push_back("李");
  myList->push_back("周");
  myList->push_back("吴");
  myList->push_back("郑");
  myList->push_back("王");

  std::cout << myList->size() << std::endl;
  std::cout << myList->empty() << std::endl;
  std::cout << myList->contains("王") << std::endl;

  myList->remove("李");
  myList->remove("郑");
  myList->print();
  return 0;
}