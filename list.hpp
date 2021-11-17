//
// Created by yacopsae on 15/11/2021.
//

#pragma once

#include <ostream>
#include "container.hpp"

template<typename T>
class ArrayList : public Container<T> {
 public:
  ArrayList() : _size(0), _currCapacity(10), _lastElement(nullptr) {}
  void push_back(T t) override;
  void insert(int index, T t) override;
  void remove(int index) override;
  void erase() override;
  int size() override;

  T *operator[](int index) {
	if (index >= _size) {
	  return nullptr;
	}

	return firstElementPtr() + index;
  }

  friend std::ostream &operator<<(std::ostream &os, const ArrayList<T> &list) {
	auto firstElement = list.firstElementPtr();
	os << "[ ";
	auto lastElIndex = list._size - 1;
	for (int i = 0; i <= lastElIndex; i++, firstElement++) {
	  if (i == lastElIndex) {
		os << *firstElement;
	  } else {
		os << *firstElement << ", ";
	  }
	}
	os << " ]" << std::endl;
	return os;
  }

 private:
  T *_lastElement;
  int _size;
  int _currCapacity;

  T *firstElementPtr() const;
  T *resize();
};

template<typename T>
void ArrayList<T>::push_back(T t) {
  if (_lastElement == nullptr) {
	_lastElement = new T[_currCapacity];
	*_lastElement = t;
  } else {
	if (_size + 1 <= _currCapacity) {
	  _lastElement++;
	  *_lastElement = t;
	} else {
	  _lastElement = resize() + _size;
	  *_lastElement = t;
	}
  }
  _size++;
}

template<typename T>
T *ArrayList<T>::resize() {
  std::cout << "Resize array from [" << _currCapacity << "] capacity to ";
  _currCapacity += _currCapacity * 2 / 3;
  std::cout << "[" << _currCapacity << "]" << std::endl;
  auto newAllocatedBlock = new T[_currCapacity];
  const auto newfirstElementPtr = newAllocatedBlock;
  auto nextElement = firstElementPtr();
  auto lastElIndex = _size - 1;

  for (int i = 0; i <= lastElIndex; i++, nextElement++, newAllocatedBlock++) {
	*newAllocatedBlock = *nextElement;
  }
  auto first = firstElementPtr();
  delete[] first;
  return newfirstElementPtr;
}

template<typename T>
int ArrayList<T>::size() {
  return _size;
}

template<typename T>
void ArrayList<T>::remove(int index) {
  if (index >= _size) {
	return;
  }
  auto *removable = firstElementPtr() + index;
  for (int i = 0; i <= _size - 1; i++) {
	auto nextBlockVal = removable + 1;
	*removable = *nextBlockVal;
	removable++;
  }
  _lastElement--;
  _size--;
}

template<typename T>
void ArrayList<T>::insert(int index, T t) {
  if (index >= _size) {
	std::cout << "Cannot do this, man" << std::endl;
  }

  if (_size + 1 >= _currCapacity) {
	_lastElement = resize() + _size;
  } else {
    _lastElement++;
  }

  auto currentElement = _lastElement;
  for (int i = _size - 1; i >= index; currentElement--, i--) {
	*currentElement = *(currentElement - 1);
  }
  *(firstElementPtr() + index - 1) = t;
  _size++;
}

template<typename T>
void ArrayList<T>::erase() {
  auto addr = _lastElement - _size + 1;
  delete[] addr;
  _lastElement = nullptr;
  _size = 0;
}

template<typename T>
T *ArrayList<T>::firstElementPtr() const {
  return _lastElement - _size + 1;
}
