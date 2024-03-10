//
// Created by propolisss on 25.02.24.
//

#include "Win.h++"

Win::Win(QWidget* parent) : QWidget(parent), prevConvert(0) {
  lineEdit = new QLineEdit("", this);
  button = new QPushButton("convert", this);
  textEdit = new QTextEdit(this);
  layout = new QVBoxLayout(this);
  textEdit->setReadOnly(true);
  layout->addWidget(lineEdit);
  layout->addWidget(button);
  layout->addWidget(textEdit);
  connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(add()));
  connect(button, SIGNAL(clicked()), this, SLOT(convert()));
}

void Win::add() {
  textEdit->setText(QString("input: " + lineEdit->text()));
  prevConvert = 0;
}

void Win::convert() {
  if (prevConvert == 1) {
    textEdit->append(lineEdit->text().toLower());
  } else if (prevConvert == 0) {
    textEdit->append(lineEdit->text().toUpper());
  }
  ++prevConvert;
}