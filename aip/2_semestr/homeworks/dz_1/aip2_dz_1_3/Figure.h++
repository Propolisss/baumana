//
// Created by propolisss on 09.03.24.
//

#ifndef AIP2_DZ_1_3__FIGURE_H_
#define AIP2_DZ_1_3__FIGURE_H_

#include <QPainter>

class Figure {
 protected:
  double width;
  double height;
  virtual void draw(QPainter* painter) = 0;
 public:
  Figure(double, double);
  void move(double, QPainter*, double, double);
  virtual ~Figure() = default;
};

#endif //AIP2_DZ_1_3__FIGURE_H_
