#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QWidget
{
  Q_OBJECT

public:
  MainWin(QWidget *parent = nullptr);
  ~MainWin();

private slots:
  void on_pushButton_3_clicked();

  void on_pushButton_6_clicked();

private:
  Ui::MainWin *ui;
  double res;
  QChar oper;
};
#endif // MAINWIN_H
