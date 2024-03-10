#include "addform.h"
#include "ui_addform.h"
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <fstream>
#include "widget.h"

AddForm::AddForm(void* par, QWidget* parent) :
    QDialog(parent),
    parentForm(par),
    ui(new Ui::AddForm) {
  ui->setupUi(this);
}

AddForm::~AddForm() {
  delete ui;
}

void AddForm::on_pushButton_clicked() {
  std::ofstream out;
  out.open("..//data_base.txt", std::ios_base::app);
  QString surname = ui->surnameLineEdit->text();
  QString name = ui->nameLineEdit->text();
  QString phone = ui->phoneLineEdit->text();
  QString adress = ui->adressLineEdit->text();
  if (surname.isEmpty() || name.isEmpty() || phone.isEmpty() || adress.isEmpty()) {
    return;
  }
  out << surname.toStdString() << '\n';
  out << name.toStdString() << '\n';
  out << phone.toStdString() << '\n';
  out << adress.toStdString() << '\n';
  out.close();
  ((Widget*)parentForm)->setDataBase(surname, name, phone, adress);
}
