//
// Created by propolisss on 10.03.24.
//

#ifndef OLYMP__CHARELEMENT_HPP_
#define OLYMP__CHARELEMENT_HPP_

#include "Element.hpp"

class CharElement : public Element {
 private:
  char symb;
 public:
  explicit CharElement(char ch = '@');
  void AddToQt(QTextEdit*) override;
  int64_t GetSortId() const override;

  void Print() const override;
};

#endif //OLYMP__CHARELEMENT_HPP_
