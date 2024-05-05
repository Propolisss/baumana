#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget), arr(nullptr) {
  ui->setupUi(this);
  ui->addElemButton->setEnabled(false);
  ui->showAllButton->setEnabled(false);
  ui->bigTextEdit->setReadOnly(true);
  ui->bigTextEdit->setEnabled(true);
  ui->elemLine->setReadOnly(true);
  ui->elemLine->setEnabled(false);
}

void Widget::on_sizeButton_clicked() {
  if (ui->sizeLine->text().toLongLong()) {
    ui->sizeLine->setEnabled(false);
    ui->sizeLine->setReadOnly(true);
    ui->sizeButton->setEnabled(false);
    ui->showAllButton->setEnabled(true);
    ui->addElemButton->setEnabled(true);
    ui->elemLine->setReadOnly(false);
    ui->elemLine->setEnabled(true);
    arr = new Array(ui->sizeLine->text().toLongLong());
  }
  ui->elemLine->setFocus();
}

Widget::~Widget() {
  delete ui;
  delete arr;
}
void Widget::on_addElemButton_clicked() {
  if (ui->elemLine->text().isEmpty()) {
    return;
  }
  if (ui->elemLine->text().size() > 1 && !ui->elemLine->text().toLongLong()) {
    return;
  }
  bool flag = true;
  for (auto symb : ui->elemLine->text().toStdString()) {
    if (symb > '9' || symb < '0') {
      flag = false;
      break;
    }
  }
  if (flag) {
    arr->AddInt(ui->elemLine->text().toLongLong());
  } else {
    arr->AddChar(ui->elemLine->text().toStdString()[0]);
  }
  ui->elemLine->clear();
  ui->elemLine->setFocus();
}

void Widget::on_showAllButton_clicked() {
  ui->bigTextEdit->clear();
  for (size_t i = 0; i < arr->Size(); ++i) {
    arr->AddToQt(ui->bigTextEdit, i);
  }
}

void Widget::on_sizeLine_returnPressed() {
  on_sizeButton_clicked();
}

void Widget::on_elemLine_returnPressed() {
  on_addElemButton_clicked();
}
