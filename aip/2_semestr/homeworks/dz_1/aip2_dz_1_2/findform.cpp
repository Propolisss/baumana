#include "findform.h"
#include "ui_findform.h"
#include "widget.h"

FindForm::FindForm(void* par, QWidget* parent) :
    QDialog(parent),
    parentForm(par),
    ui(new Ui::FindForm) {
  ui->setupUi(this);
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

