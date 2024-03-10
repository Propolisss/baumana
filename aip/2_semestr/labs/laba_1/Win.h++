//
// Created by propolisss on 25.02.24.
//

#ifndef CALC__WIN_H_
#define CALC__WIN_H_
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QValidator>
#include <iostream>
#include <QString>

class Win : public QWidget {
 Q_OBJECT
 private slots:
  void add();
  void convert();
 protected:
  QLineEdit* lineEdit;
  QPushButton* button;
  QTextEdit* textEdit;
  QVBoxLayout* layout;
  int prevConvert;
 public:
  explicit Win(QWidget* parent = nullptr);
  ~Win() override = default;
};

#endif //CALC__WIN_H_
