//
// Created by propolisss on 16.03.24.
//

#ifndef RK_1__BOOK_H_
#define RK_1__BOOK_H_
#include <string>

class Book {
 private:
  std::string title;
  std::string nameAuthor;
 public:
  Book();
  Book(const std::string&, const std::string&);
  [[nodiscard]] std::string GetTitle() const;
  [[nodiscard]] std::string GetNameAuthor() const;
};

bool operator<(const Book&, const Book&);

#endif //RK_1__BOOK_H_
