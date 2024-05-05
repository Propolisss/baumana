//
// Created by propolisss on 09.03.24.
//

#ifndef AIP2_DZ_1_3__AREA_H_
#define AIP2_DZ_1_3__AREA_H_
#include "Ellipse.h++"
#include <QWidget>
#include <QTimer>

class Area : public QWidget {
 private:
  int myTimer;
  double alpha1;
  double alpha2;
  double alpha3;
  double alpha4;
  Ellipse* ellipse1;
  Ellipse* ellipse2;
  Ellipse* ellipse3;
  Ellipse* circle;
 protected:
  void paintEvent(QPaintEvent* event) override;
  void timerEvent(QTimerEvent* event) override;
  void showEvent(QShowEvent* event) override;
  void hideEvent(QHideEvent* event) override;
 public:
  explicit Area(QWidget* parent = nullptr);
  ~Area() override;
};

#endif //AIP2_DZ_1_3__AREA_H_
