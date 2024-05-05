//
// Created by propolisss on 11.03.24.
//
#include "ArrayParent.hpp"

template<>
void ArrayParent<Element>::AddElement(const std::string& elem) {
  bool flag = true;
  for (auto symb : elem) {
    if ('0' > symb || symb > '9') {
      flag = false;
      break;
    }
  }
  if (flag) {
    arr[realSize++] = new IntElement(std::stoll(elem));
  } else {
    if (!('a' <= elem[0] && elem[0] <= 'z' || 'A' <= elem[0] && elem[0] <= 'Z')) {
      throw ("not latin symbol");
    }
    arr[realSize++] = new CharElement(elem[0]);
  }
}

template<>
void ArrayParent<Element>::PrintElements() const {
  for (size_t i = 0; i < realSize; ++i) {
    arr[i]->Print();
    std::cout << ' ';
  }
  std::cout << std::endl;
}