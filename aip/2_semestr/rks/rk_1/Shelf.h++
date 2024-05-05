//
// Created by propolisss on 16.03.24.
//

#ifndef RK_1__SHELF_H_
#define RK_1__SHELF_H_
#include "Book.h++"
#include <vector>
#include <QTextEdit>

class Shelf {
 protected:
  std::vector<Book>* books;
  size_t size;
  size_t realSize;
 public:
  Shelf();
  Shelf(int);
  size_t Size() const;
  void addBook(const std::string&, const std::string&);
  void PrintBooks() const;
  void AddToQt(QTextEdit*, const std::string&);
  Book& operator[](size_t);
  ~Shelf();
};

#endif //RK_1__SHELF_H_
