//
// Created by propolisss on 10.03.24.
//

#ifndef OLYMP__INTELEMENT_HPP_
#define OLYMP__INTELEMENT_HPP_

#include <cstdint>
#include "Element.hpp"

class IntElement : public Element {
 private:
  int64_t num;
 public:
  explicit IntElement(int64_t n = 0);

  void AddToQt(QTextEdit*) override;
  void Print() const override;

  int64_t GetSortId() const override;
};

#endif //OLYMP__INTELEMENT_HPP_
