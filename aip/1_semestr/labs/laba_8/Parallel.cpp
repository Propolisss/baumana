#include "Parallel.hpp"
#include <iostream>

Parallel::Parallel() : length(0.0), width(0.0), height(0.0) {}
Parallel::Parallel(double len, double wid, double heig) : length(std::abs(len)), width(std::abs(wid)), height(std::abs(heig)) {}
void Parallel::ShowInfo() {
  std::cout << "Length: " << length << " Width: " << width << " Height: " << height;
}
double Parallel::CalcVolume() {
  return length * width * height;
}
