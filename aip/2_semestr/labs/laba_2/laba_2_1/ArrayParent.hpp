//
// Created by propolisss on 10.03.24.
//

#ifndef OLYMP__ARRAYPARENT_HPP_
#define OLYMP__ARRAYPARENT_HPP_

#include <cstddef>
#include <string>
#include <iostream>
#include <QTextEdit>

class ArrayParent {
 protected:
  int* intArr;
  char* charArr;
  std::pair<int, int>* order;
  int intSize;
  int intRealSize;
  int charSize;
  int charRealSize;
 public:
  explicit ArrayParent(size_t);
  explicit ArrayParent();

  void AddInt(int);
  void AddChar(char);
  void AddToQt(QTextEdit*, int);
  [[nodiscard]] size_t Size() const;
  int GetInt(size_t);
  char GetChar(size_t);

  void PrintElements() const;

  ~ArrayParent();
};

#endif //OLYMP__ARRAYPARENT_HPP_
