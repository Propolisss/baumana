//
// Created by propolisss on 16.03.24.
//

#ifndef RK_1__LIBSHELF_H_
#define RK_1__LIBSHELF_H_
#include "Shelf.h++"

class LibShelf : public Shelf {
 public:
  LibShelf(int);
  void SortBooks();
};

#endif //RK_1__LIBSHELF_H_
