//
// Created by propolisss on 09.03.24.
//

#ifndef AIP2_DZ_1_3__ELLIPSE_H_
#define AIP2_DZ_1_3__ELLIPSE_H_
#include "Figure.h++"

class Ellipse : public Figure {
 protected:
  void draw(QPainter* painter) override;
 public:
  Ellipse(double, double);
};

#endif //AIP2_DZ_1_3__ELLIPSE_H_
