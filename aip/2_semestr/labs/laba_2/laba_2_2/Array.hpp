//
// Created by propolisss on 11.03.24.
//

#ifndef OLYMP__ARRAY_HPP_
#define OLYMP__ARRAY_HPP_

#include <algorithm>
#include "ArrayParent.hpp"
#include "Element.hpp"
template<class T>
class Array : public ArrayParent<T> {
 public:
  explicit Array(size_t);
  void Sort();
};

template<class T>
Array<T>::Array(size_t n) : ArrayParent<T>(n) {}

//template<class T>
//void Array<T>::Sort() {
//  std::sort(this->arr, this->arr + this->realSize, [&](const T* el1, const T* el2) {
//    return *el1 < *el2;
//  });
//}

#endif //OLYMP__ARRAY_HPP_
