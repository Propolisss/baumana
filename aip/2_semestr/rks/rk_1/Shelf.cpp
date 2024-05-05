//
// Created by propolisss on 16.03.24.
//

#include <iostream>
#include "Shelf.h++"
Shelf::Shelf() : Shelf(0) {}

Shelf::Shelf(int size_) {
  if (size_ < 0) {
    throw ("negative size given");
  }
  size = size_;
  realSize = 0;
  books = new std::vector<Book>(size);
}
void Shelf::addBook(const std::string& book, const std::string& name) {
  if (realSize >= size) {
    throw("max size");
  }
  (*books)[realSize++] = Book(book, name);
}
Shelf::~Shelf() {
  delete books;
}
void Shelf::PrintBooks() const {
  for (size_t i = 0; i < realSize; ++i) {
    std::cout << (*books)[i].GetTitle() << " : " << (*books)[i].GetNameAuthor() << std::endl;
  }
}
size_t Shelf::Size() const {
  return realSize;
}
void Shelf::AddToQt(QTextEdit* textEdit, const std::string& st) {
  textEdit->append(QString(st.c_str()));
}
Book& Shelf::operator[](size_t ind) {
  return (*books)[ind];
}
