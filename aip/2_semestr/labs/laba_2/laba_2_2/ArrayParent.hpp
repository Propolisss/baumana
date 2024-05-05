//
// Created by propolisss on 10.03.24.
//

#ifndef OLYMP__ARRAYPARENT_HPP_
#define OLYMP__ARRAYPARENT_HPP_

#include <cstddef>
#include <string>
#include "Element.hpp"
#include "IntElement.hpp"
#include "CharElement.hpp"
#include <iostream>

template<class T>
class ArrayParent {
 protected:
  T** arr;
  int size;
  int realSize;
 public:
  explicit ArrayParent(size_t);
  explicit ArrayParent();

  void AddElement(const std::string&);

  void AddElement(const T&);

  size_t Size() const;
  T& operator[](int);

  void PrintElements() const;

  ~ArrayParent();
};
template<class T>
ArrayParent<T>::ArrayParent() : T(nullptr), size(0), realSize(0) {}

template<class T>
void ArrayParent<T>::AddElement(const T& elem) {
  arr[realSize++] = new T(elem);
}

template<class T>
size_t ArrayParent<T>::Size() const {
  return realSize;
}
template<class T>
ArrayParent<T>::ArrayParent(size_t n) : size(n), realSize(0) {
  arr = new T* [n];
}

template<class T>
T& ArrayParent<T>::operator[](int i) {
  if (i < 0) {
    throw("negative index given");
  }
  if (i >= Size()) {
    throw("index more than size");
  }
  return *arr[i];
}

template<class T>
void ArrayParent<T>::PrintElements() const {
  for (size_t i = 0; i < realSize; ++i) {
    std::cout << *arr[i] << ' ';
  }
  std::cout << std::endl;
}

template<class T>
ArrayParent<T>::~ArrayParent() {
  if (arr) {
    for (size_t i = 0; i < realSize; ++i) {
      delete arr[i];
    }
    delete[] arr;
  }
}

#endif //OLYMP__ARRAYPARENT_HPP_
