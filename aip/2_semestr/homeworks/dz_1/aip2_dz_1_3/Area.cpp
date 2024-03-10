//
// Created by propolisss on 09.03.24.
//

#include "Area.h++"
#include <QTimerEvent>
#include <iostream>

Area::Area(QWidget* parent) : QWidget(parent) {
  ellipse1 = new Ellipse(150, 50);
  ellipse2 = new Ellipse(50, 100);
  alpha1 = 0;
  alpha2 = 0;
}

void Area::showEvent(QShowEvent* event) {
  myTimer = startTimer(10);
}

void Area::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setPen(QPen(Qt::black, 2));
  painter.setBrush(Qt::white);
  painter.translate(width() / 2, height() / 2);
  ellipse1->move(alpha1, &painter, width(), height());
  ellipse2->move(alpha2, &painter, width(), height());
}

void Area::timerEvent(QTimerEvent* event) {
  if (event->timerId() == myTimer) {
    alpha1 += 0.25;
    alpha2 += 0.5;
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
