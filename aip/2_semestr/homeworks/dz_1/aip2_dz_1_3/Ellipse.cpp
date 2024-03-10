//
// Created by propolisss on 09.03.24.
//

#include <iostream>
#include "Ellipse.h++"
Ellipse::Ellipse(double width_, double height_) : Figure(width_, height_) {

}
void Ellipse::draw(QPainter* painter) {
  painter->drawEllipse(-width / 2, -height / 2, width, height);
}
