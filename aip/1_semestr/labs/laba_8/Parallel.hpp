#ifndef LABA_8__PARALLEL_HPP_
#define LABA_8__PARALLEL_HPP_

class Parallel {
 public:
  Parallel();
  Parallel(double len, double wid = 0.0, double heig = 0.0);
  void ShowInfo();
  double CalcVolume();

 protected:
  double length;
  double width;
  double height;
};

#endif //LABA_8__PARALLEL_HPP_
