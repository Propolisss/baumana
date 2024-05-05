#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget), arr(nullptr) {
  ui->setupUi(this);
  ui->addElemButton->setEnabled(false);
  ui->showAllButton->setEnabled(false);
  ui->sortButton->setEnabled(false);
  ui->bigTextEdit->setReadOnly(true);
  ui->bigTextEdit->setEnabled(true);
  ui->elemLine->setReadOnly(true);
  ui->elemLine->setEnabled(false);
  ui->nameLine->setReadOnly(true);
  ui->nameLine->setEnabled(false);
}

void Widget::on_sizeButton_clicked() {
  if (!ui->sizeLine->text().toLongLong()) {
    return;
  }
  ui->sizeLine->setEnabled(false);
  ui->sizeLine->setReadOnly(true);
  ui->sizeButton->setEnabled(false);
  ui->showAllButton->setEnabled(true);

  ui->addElemButton->setEnabled(true);
  ui->sortButton->setEnabled(true);
  ui->elemLine->setReadOnly(false);
  ui->elemLine->setEnabled(true);
  ui->nameLine->setReadOnly(false);
  ui->nameLine->setEnabled(true);
  arr = new LibShelf(ui->sizeLine->text().toLongLong());
  ui->nameLine->setFocus();
}

Widget::~Widget() {
  delete ui;
  delete arr;
}
void Widget::on_addElemButton_clicked() {
  if (ui->elemLine->text().isEmpty()) {
    return;
  }
  arr->addBook(ui->nameLine->text().toStdString(), ui->elemLine->text().toStdString());
  ui->elemLine->clear();
  ui->nameLine->setFocus();
  ui->nameLine->clear();
}

void Widget::on_showAllButton_clicked() {
  ui->bigTextEdit->clear();
  for (size_t i = 0; i < arr->Size(); ++i) {
    (*arr).AddToQt(ui->bigTextEdit, (*arr)[i].GetTitle() + " : " + (*arr)[i].GetNameAuthor());
  }
}

void Widget::on_sizeLine_returnPressed() {
  on_sizeButton_clicked();
}

void Widget::on_elemLine_returnPressed() {
  on_addElemButton_clicked();
}

void Widget::on_sortButton_clicked() {
  arr->SortBooks();
  on_showAllButton_clicked();
}
