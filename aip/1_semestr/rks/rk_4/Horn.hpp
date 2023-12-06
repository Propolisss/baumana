#ifndef RK_4__HORN_HPP_
#define RK_4__HORN_HPP_

class Horn {
 public:
  Horn() : length(0.0) {}

  Horn(double len) : length(len) {}

  double GetLen() {
    return length;
  }
 private:
  double length;
};

#endif //RK_4__HORN_HPP_
