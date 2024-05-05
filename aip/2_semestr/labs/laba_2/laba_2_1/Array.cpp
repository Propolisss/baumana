//
// Created by propolisss on 16.03.24.
//
#include "Array.hpp"

Array::Array(size_t n) : ArrayParent(n) {}

void Array::Sort() {
  std::sort(order, order + Size(), [&](const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) {
    return pair1.second < pair2.second;
  });
}
