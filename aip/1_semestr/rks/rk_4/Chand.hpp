#ifndef RK_4__CHAND_HPP_
#define RK_4__CHAND_HPP_
#include "Horn.hpp"
#include "Bulp.hpp"
#include <vector>

class Chand : Bulp {
 public:
  Chand() : diameter(0.0), powerBulps(0.0), countBulps(0) {}

  void AddHorn(double horn_, double bulp_) {
    bulps.push_back(Bulp(bulp_));
    powerBulps += bulp_;
    diameter += horn_;
    ++countBulps;
  }

  double GetDiam() {
    return diameter;
  }

  double GetPower() {
    return powerBulps;
  }

  size_t GetCount() {
    return countBulps;
  }

 private:
  double diameter;
  double powerBulps;
  size_t countBulps;
  std::vector<Bulp> bulps;
};

#endif //RK_4__CHAND_HPP_
