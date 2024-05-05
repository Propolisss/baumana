//
// Created by propolisss on 16.03.24.
//

#include <algorithm>
#include "LibShelf.h++"
void LibShelf::SortBooks() {
  std::sort((*books).begin(), (*books).begin() + realSize);
}
LibShelf::LibShelf(int size) : Shelf(size) {}
