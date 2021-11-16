//
// Created by yacopsae on 15/11/2021.
//

#pragma once
#include <ostream>
template <typename T>
class Container {
 public:
  virtual void push_back(T t) = 0;
  virtual void insert(int index, T t) = 0;
  virtual void remove(int index) = 0;
  virtual void erase() = 0;
  virtual int size() = 0;

};


