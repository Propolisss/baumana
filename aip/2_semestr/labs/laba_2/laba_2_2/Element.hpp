//
// Created by propolisss on 10.03.24.
//

#ifndef OLYMP__ELEMENT_HPP_
#define OLYMP__ELEMENT_HPP_

#include <cstdint>
#include <QTextEdit>

class Element {
 public:
  virtual void Print() const = 0;

  virtual int64_t GetSortId() const = 0;

  virtual void AddToQt(QTextEdit*) = 0;

  Element() = default;

  virtual ~Element() = default;
};


#endif //OLYMP__ELEMENT_HPP_
