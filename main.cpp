//
// Created by yacopsae on 15/11/2021.
//
#include <iostream>
#include "list.hpp"
#include "ptr_list.hpp"

int main() {
  ArrayList<int> list;
  for (int i = 0; i <= 9; i++) {
	list.push_back(i);
  }

  std::cout << "ожидаемый результат:  0, 1, 2, 3, 4, 5, 6, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << list << std::endl;


  std::cout << "ожидаемый результат:  10" << std::endl;
  std::cout << "полученный результат: " << list.size() << std::endl;


  list.remove(2);
  list.remove(3);
  list.remove(4);
  std::cout << "ожидаемый результат:  0, 1, 3, 5, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << list << std::endl;


  list.insert(0, 10);
  std::cout << "ожидаемый результат:  10, 0, 1, 3, 5, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << list << std::endl;


  list.insert(list.size() / 2, 20);
  std::cout << "ожидаемый результат:  10, 0, 1, 3, 20, 5, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << list << std::endl;

  PtrList<int> ptr_list;
  for (int i = 0; i <= 9; i++) {
	ptr_list.push_back(i);
  }
  std::cout << "ожидаемый результат:  0, 1, 2, 3, 4, 5, 6, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << ptr_list << std::endl;

  std::cout << "ожидаемый результат:  10" << std::endl;
  std::cout << "полученный результат: " << ptr_list.size() << std::endl;

  ptr_list.remove(2);
  ptr_list.remove(3);
  ptr_list.remove(4);
  std::cout << "ожидаемый результат:   0, 1, 3, 5, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << ptr_list << std::endl;


  ptr_list.insert(0, 10);
  std::cout << "ожидаемый результат:  10, 0, 1, 3, 5, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << ptr_list << std::endl;


  ptr_list.insert(list.size() / 2, 20);
  std::cout << "ожидаемый результат:  10, 0, 1, 3, 20, 5, 7, 8, 9" << std::endl;
  std::cout << "полученный результат: " << ptr_list << std::endl;


  return 0;
}
