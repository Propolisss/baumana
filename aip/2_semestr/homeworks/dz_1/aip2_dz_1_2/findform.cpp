#include <QKeyEvent>
#include <iostream>
#include "findform.h"
#include "ui_findform.h"
#include "widget.h"

FindForm::FindForm(void* par, QWidget* parent) :
    QDialog(parent),
    parentForm(par),
    ui(new Ui::FindForm) {
  ui->setupUi(this);
  ui->pushButton->setAutoDefault(false);
  ui->pushButton_3->setAutoDefault(false);
  ui->surnameLineEdit->installEventFilter(this);
  ui->pushButton->installEventFilter(this);
  ui->pushButton_3->installEventFilter(this);
}

FindForm::~FindForm() {
  delete ui;
}

void FindForm::on_pushButton_clicked() {
  QString surname = ui->surnameLineEdit->text();
  QString name = ui->nameLineEdit->text();
  QString phone = ui->phoneLineEdit->text();
  QString adress = ui->adressLineEdit->text();
  if ((surname.isEmpty() && name.isEmpty()) || phone.isEmpty() || adress.isEmpty()) {
    return;
  }
  ((Widget*) parentForm)->showFindedDataBase(surname, name, phone, adress);
}

void FindForm::on_nameLineEdit_returnPressed() {
  ui->phoneLineEdit->setFocus();
}

void FindForm::on_surnameLineEdit_returnPressed() {
  ui->nameLineEdit->setFocus();
}

void FindForm::on_phoneLineEdit_returnPressed() {
  ui->adressLineEdit->setFocus();
}

void FindForm::on_adressLineEdit_returnPressed() {
  ui->pushButton->setAutoDefault(true);
  ui->pushButton_3->setAutoDefault(true);
  ui->adressLineEdit->clearFocus();
  ui->pushButton->setFocus();
}
bool FindForm::eventFilter(QObject* obj, QEvent* event) {
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
