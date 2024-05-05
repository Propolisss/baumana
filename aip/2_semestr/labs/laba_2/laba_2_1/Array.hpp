//
// Created by propolisss on 11.03.24.
//

#ifndef OLYMP__ARRAY_HPP_
#define OLYMP__ARRAY_HPP_

#include <algorithm>
#include "ArrayParent.hpp"

class Array : public ArrayParent {
 public:
  explicit Array(size_t);
  void Sort();
};

#endif //OLYMP__ARRAY_HPP_
