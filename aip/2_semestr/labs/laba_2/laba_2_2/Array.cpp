//
// Created by propolisss on 16.03.24.
//
#include "Array.hpp"

template<>
void Array<Element>::Sort() {
  std::sort(this->arr, this->arr + this->realSize, [&](const Element* el1, const Element* el2) {
    return el1->GetSortId() < el2->GetSortId();
  });
}
