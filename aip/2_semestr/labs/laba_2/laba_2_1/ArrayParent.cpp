//
// Created by propolisss on 11.03.24.
//
#include "ArrayParent.hpp"
ArrayParent::ArrayParent()
    : intArr(nullptr), charArr(nullptr), intSize(0), intRealSize(0), charRealSize(0), charSize(0), order(nullptr) {}

void ArrayParent::AddInt(int num) {
  intArr[intRealSize] = num;
  order[Size()] = std::make_pair(Size(), 1);
  std::cout << Size() << ' ' << num << std::endl;
  ++intRealSize;
}

size_t ArrayParent::Size() const {
  return intRealSize + charRealSize;
}

ArrayParent::ArrayParent(size_t n) : intSize(n), charSize(n), intRealSize(0), charRealSize(0) {
  intArr = new int[n];
  charArr = new char[n];
  order = new std::pair<int, int>[n];
}
void ArrayParent::AddChar(char symb) {
  charArr[charRealSize] = symb;
  order[Size()] = std::make_pair(Size(), 0);
  std::cout << Size() << ' ' << symb << std::endl;
  ++charRealSize;
}

void ArrayParent::PrintElements() const {
  for (size_t i = 0; i < Size(); ++i) {
    if (order[i].second) {
      std::cout << intArr[order[i].first] << ' ';
    } else {
      std::cout << charArr[order[i].first] << ' ';
    }
  }
}

ArrayParent::~ArrayParent() {
  delete intArr;
  delete charArr;
  delete order;
}
int ArrayParent::GetInt(size_t ind) {
  int temp = 0;
  for (size_t i = 0; i < Size(); ++i) {
    if (order[i].second) {
      if (order[i].first == ind) {
        return intArr[temp];
      }
      ++temp;
    }
  }
  throw ("not found int");
}
char ArrayParent::GetChar(size_t ind) {
  int temp = 0;
  for (size_t i = 0; i < Size(); ++i) {
    if (order[i].second == 0) {
      if (order[i].first == ind) {
        return charArr[temp];
      }
      ++temp;
    }
  }
  throw ("not found char");
}
void ArrayParent::AddToQt(QTextEdit* textEdit, int ind) {
  try {
    textEdit->append(QString::number(GetInt(ind)));
  } catch (...) {
    std::cout << "cathed\n";
    textEdit->append(QString(GetChar(ind)));
  }
}
