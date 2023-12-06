#include <iostream>
#include "Chand.hpp"


int main() {
  Chand chand;
  size_t n = 0;
  double lenHorn = 0.0;
  std::cout << "Введите количество рожков и их длину: ";
  std::cin >> n >> lenHorn;
  std::cout << "Вводите мощность " << n << " лампочек:" << std::endl;
  double power = 0;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> power;
    chand.AddHorn(lenHorn, power);
  }
  std::cout << "Количество рожков люстры: " << chand.GetCount() << std::endl;
  std::cout << "Диаметр люстры: " << chand.GetDiam() << std::endl;
  std::cout << "Мощность люстры: " << chand.GetPower() << std::endl;



  return 0;
}