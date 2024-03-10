//
// Created by propolisss on 09.03.24.
//

#include "Figure.h++"
#include <iostream>

Figure::Figure(double width_, double height_) : width(width_), height(height_) {

}
void Figure::move(double alpha, QPainter* painter, double width_, double height_) {
  painter->rotate(alpha);
  draw(painter);
}
