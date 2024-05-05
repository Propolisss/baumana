#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Array.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT
 public:
  Widget(QWidget* parent = nullptr);
  ~Widget();

private slots:
  void on_sizeButton_clicked();

  void on_addElemButton_clicked();

  void on_showAllButton_clicked();

  void on_sizeLine_returnPressed();

  void on_elemLine_returnPressed();

  void on_sortButton_clicked();

private:
  Ui::Widget* ui;
  Array<Element>* arr;
};
#endif // WIDGET_H
