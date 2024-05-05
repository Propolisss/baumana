//
// Created by propolisss on 10.03.24.
//

#include <iostream>
#include "IntElement.hpp"

IntElement::IntElement(int64_t n) : Element(), num(n) {
}

int64_t IntElement::GetSortId() const {
  return num;
}

void IntElement::Print() const {
  std::cout << num;
}
void IntElement::AddToQt(QTextEdit* textEdit) {
  textEdit->append(QString::number(num) + ' ');
}


