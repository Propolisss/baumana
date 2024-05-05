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
  ui->pushButton->setAutoDefault(false);
  ui->pushButton_3->setAutoDefault(false);
  ui->surnameLineEdit->installEventFilter(this);
  ui->pushButton->installEventFilter(this);
  ui->pushButton_3->installEventFilter(this);
}

AddForm::~AddForm() {
  delete ui;
}

void AddForm::on_pushButton_clicked() {
  std::ofstream out;
  out.open("//home//propolisss//baumana//aip//2_semestr//homeworks//dz_1//aip2_dz_1_2//data_base.txt", std::ios_base::app);
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
  ((Widget*) parentForm)->setDataBase(surname, name, phone, adress);
}

void AddForm::on_surnameLineEdit_returnPressed() {
  ui->nameLineEdit->setFocus();
}

void AddForm::on_nameLineEdit_returnPressed() {
  ui->phoneLineEdit->setFocus();
}

void AddForm::on_phoneLineEdit_returnPressed() {
  ui->adressLineEdit->setFocus();
}

void AddForm::on_adressLineEdit_returnPressed() {
  ui->pushButton->setAutoDefault(true);
  ui->pushButton_3->setAutoDefault(true);
  ui->adressLineEdit->clearFocus();
  ui->pushButton->setFocus();
}

bool AddForm::eventFilter(QObject* obj, QEvent* event) {
  if (event->type() == QEvent::FocusIn) {
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(QApplication::focusWidget());
    QPushButton* button = qobject_cast<QPushButton*>(QApplication::focusWidget());
    if (lineEdit == ui->surnameLineEdit) {
      ui->pushButton->setAutoDefault(false);
      ui->pushButton->setDefault(false);
      ui->pushButton_3->setAutoDefault(false);
      ui->pushButton_3->setDefault(false);
      ui->pushButton->clearFocus();
      ui->pushButton_3->clearFocus();
    } else if (button == ui->pushButton || button == ui->pushButton_3) {
      ui->pushButton->setAutoDefault(true);
      ui->pushButton->setDefault(true);
      ui->pushButton_3->setAutoDefault(true);
      ui->pushButton_3->setDefault(true);
    }
  }
  return QDialog::eventFilter(obj, event);
}