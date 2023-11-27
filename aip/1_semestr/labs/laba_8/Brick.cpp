#include "Brick.hpp"
#include <iostream>

Brick::Brick() : Parallel(), Mass(0.0) {}
Brick::Brick(double len, double wid, double heig, double mass) : Parallel(len, wid, heig), Mass(std::abs(mass)) {}
void Brick::ShowInfo() {
  Parallel::ShowInfo();
  std::cout << " Mass: " << Mass;
}
double Brick::CalcDensity() {
  return Mass / CalcVolume();
}
