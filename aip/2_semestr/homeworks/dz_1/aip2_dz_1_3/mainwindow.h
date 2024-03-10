#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Area.h++"

class MainWindow : public QMainWindow {
 Q_OBJECT
 private:
  Area* area;
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;
};
#endif // MAINWINDOW_H
