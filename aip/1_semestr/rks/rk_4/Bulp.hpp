#ifndef RK_4__BULP_HPP_
#define RK_4__BULP_HPP_

class Bulp {
 public:
  Bulp() : power(0.0) {}

  Bulp(double power_) : power(power_) {}

  double GetPower() {
    return power;
  }

 private:
  double power;
};

#endif //RK_4__BULP_HPP_
