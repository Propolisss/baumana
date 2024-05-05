//
// Created by propolisss on 09.03.24.
//

#include "Area.h++"
#include <QTimerEvent>
#include <iostream>

Area::Area(QWidget* parent) : QWidget(parent), alpha1(0.0), alpha2(0.0), alpha3(0.0), alpha4(0.0) {
  ellipse1 = new Ellipse(150, 50);
  ellipse2 = new Ellipse(50, 100);
  ellipse3 = new Ellipse(50, 100);
  circle = new Ellipse(100, 100);
}

void Area::showEvent(QShowEvent* event) {
  myTimer = startTimer(10);
}

void Area::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setPen(QPen(Qt::black, 2));
  painter.setBrush(Qt::white);

  painter.save();
  painter.translate(width() / 2, height() / 2);
  ellipse1->move(alpha1, &painter, width(), height());
  ellipse2->move(alpha2, &painter, width(), height());
  painter.restore();

  painter.save();
  painter.translate(width() / 2 - 100 - 40, height() / 2);
  ellipse3->move(alpha3, &painter, width(), height());
  painter.restore();

  painter.translate(width() / 2 + 125 + 40, height() / 2);
  circle->move(alpha4, &painter, width(), height());
  painter.setBrush(QBrush(palette().color(QPalette::Window)));
  painter.setPen(QPen(palette().color(QPalette::Window), 2));
  painter.drawRect(0, -50, 50, 50);
}

void Area::timerEvent(QTimerEvent* event) {
  if (event->timerId() == myTimer) {
    alpha1 += 0.25;
    alpha2 += 0.5;
    alpha3 += 2;
    alpha4 += 1;
    update();
  } else {
    QWidget::timerEvent(event);
  }
}

void Area::hideEvent(QHideEvent* event) {
  killTimer(myTimer);
}

Area::~Area() {
  delete ellipse1;
  delete ellipse2;
}
