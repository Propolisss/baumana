//
// Created by propolisss on 16.03.24.
//

#include "Book.h++"
Book::Book() : Book("", "") {}

Book::Book(const std::string& title_, const std::string& name_) : title(title_), nameAuthor(name_) {}

std::string Book::GetTitle() const {
  return title;
}
std::string Book::GetNameAuthor() const {
  return nameAuthor;
}
bool operator<(const Book& b1, const Book& b2) {
  return b1.GetNameAuthor() < b2.GetNameAuthor();
}
