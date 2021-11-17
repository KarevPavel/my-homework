//
// Created by yacopsae on 16/11/2021.
//

#pragma once

#include <ostream>

#include "container.hpp"

template<typename T>
class PtrList: public Container<T> {
 private:
  class Entry {
   public:
	explicit Entry(T value) : value(value), next(nullptr) {}
	Entry(T value, Entry *next) : next(next), value(value) {}

	Entry *next;
	T value;

	Entry *last() {
	  for (auto r = this; r != nullptr; r = r->next) {
		if (r->next == nullptr) {
		  return r;
		}
	  }
	  return nullptr;
	}

	Entry* erase() {
	  auto r = this->next;
	  while (r != nullptr) {
	   r = r->erase();
	  }
	  delete this;
	  return nullptr;
	}
  };



 public:
  PtrList(): root(nullptr) {}
  void push_back(T t);
  void insert(int index, T t);
  void remove(int index);
  void erase();
  int size();

  friend std::ostream &operator<<(std::ostream &os, const PtrList<T> &list) {
	auto r = list.root;
	os << "[ ";
	for (;r != nullptr; r = r->next) {
	  if (r->next == nullptr) {
		os << r->value;
	  } else {
		os << r->value << ", ";
	  }
	}
	os << " ]" << std::endl;
	return os;
  }

 private:
  Entry * root;
};


template<typename T>
void PtrList<T>::push_back(T t) {
  if (root == nullptr) {
	root = new Entry(t);
	return;
  }
  auto entry = new Entry(t);
  auto _last = root->last();
  _last->next = entry;
}

template<typename T>
void PtrList<T>::insert(int index, T t) {
  for (auto r = this->root, listIndex = 0, prevTmp = r; r != nullptr; r = r->next, listIndex++) {
    if (index == 0) {
      root = new Entry(t, r);
      return;
    }

	if (listIndex == index - 1) {
	  prevTmp = r;
	}

    if (listIndex == index) {
	  prevTmp->next = new Entry(t, r);
	}
  }
}
template<typename T>
void PtrList<T>::remove(int index) {
  for (auto r = this->root, listIndex = 0, prevTmp = r; r != nullptr; r = r->next, listIndex++) {
    if (listIndex == index - 1 || index == 0) {
      prevTmp = r;
    }

	if (listIndex == index) {
	  prevTmp->next = r->next;
	  delete r;
	  return;
	}
  }
}
template<typename T>
void PtrList<T>::erase() {
  this->root = this->root->erase();
}

template<typename T>
int PtrList<T>::size() {
  for (auto r = this->root, counter = 1; r != nullptr; r = r->next, counter++) {
	if (r->next == nullptr) {
	  return counter;
	}
  }
  return 0;
}

