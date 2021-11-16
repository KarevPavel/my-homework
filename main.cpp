//
// Created by yacopsae on 15/11/2021.
//
#include <iostream>
#include "list.hpp"

int main() {
  CustomList<int> list{};
  for (int i = 0; i <= 9; i++) {
	list.push_back(i);
  }
  std::cout << "Inserted " << list.size() << " elements:" << std::endl;
  std::cout << list << std::endl;
  list.remove(7);
  list.remove(5);
  list.remove(3);
  std::cout << "Deleted indexes 7, 5, 3:" << std::endl;
  std::cout << list << std::endl;
  list.erase();
  std::cout << "erased:" << std::endl;
  std::cout << list << std::endl;
  for (int i = 1; i <= 74; i++) {
	list.push_back(i);
  }
  std::cout << "Inserted " << list.size() << " elements:" << std::endl;
  std::cout << list << std::endl;

  std::cout << "At Index 10: " << list[10] << std::endl;

  list.insert(0, 99);
  std::cout << list << std::endl;
  list.erase();
  std::cout << "erased:" << std::endl;
  std::cout << list << std::endl;


  return 0;
}
