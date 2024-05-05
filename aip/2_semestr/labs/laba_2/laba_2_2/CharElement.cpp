//
// Created by propolisss on 10.03.24.
//

#include <iostream>
#include "CharElement.hpp"

CharElement::CharElement(char ch) : symb(ch) {}

void CharElement::Print() const {
  std::cout << symb;
}

int64_t CharElement::GetSortId() const {
  return static_cast<size_t>(symb);
}
void CharElement::AddToQt(QTextEdit* textEdit) {
  textEdit->append(QString(symb) + ' ');
}


