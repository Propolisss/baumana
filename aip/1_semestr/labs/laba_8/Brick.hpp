#ifndef LABA_8__BRICK_HPP_
#define LABA_8__BRICK_HPP_
#include "Parallel.hpp"

class Brick : public Parallel {
 public:
  Brick();
  Brick(double len, double wid = 0.0, double heig = 0.0, double mass = 0.0);
  void ShowInfo();
  double CalcDensity();

 private:
  double Mass;
};

#endif //LABA_8__BRICK_HPP_
