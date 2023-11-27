#include <iostream>
#include "Brick.hpp"


int main() {
  Brick brick(1, 2, 3, 5);
  brick.ShowInfo();
  std::cout << std::endl;
  std::cout << brick.CalcVolume() << std::endl;
  std::cout << brick.CalcDensity() << std::endl << std::endl;

  Parallel par(5, 6, 7);
  par.ShowInfo();
  std::cout << std::endl;
  std::cout << par.CalcVolume() << std::endl;


  return 0;
}
