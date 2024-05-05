#include <QKeyEvent>
#include <iostream>
#include "findform.h"
#include "ui_findform.h"
#include "widget.h"
#include <QMessageBox>

FindForm::FindForm(void* par, QWidget* parent) :
    QDialog(parent),
    parentForm(par),
    ui(new Ui::FindForm) {
  ui->setupUi(this);
  ui->pushButton->setAutoDefault(false);
  ui->pushButton_3->setAutoDefault(false);
  ui->modelLineEdit->installEventFilter(this);
  ui->pushButton->installEventFilter(this);
  ui->pushButton_3->installEventFilter(this);
  setWindowTitle("Поиск обуви");
}

FindForm::~FindForm() {
  delete ui;
}

void FindForm::on_pushButton_clicked() {
  ((Widget*) parentForm)->updateDataBase();
  QString model = ui->modelLineEdit->text();
  QString sizeOfShoe = ui->sizeLineEdit->text();
  if ((model.isEmpty() || sizeOfShoe.isEmpty())) {
      QMessageBox::critical(this, "Ошибка", "Заполните данные до конца");
    return;
  }
  auto temp = QString();
  ((Widget*) parentForm)->showFindedDataBase(model, sizeOfShoe);
}

void FindForm::on_modelLineEdit_returnPressed() {
  ui->sizeLineEdit->setFocus();
}

void FindForm::on_sizeLineEdit_returnPressed() {
  ui->pushButton->setAutoDefault(true);
  ui->pushButton_3->setAutoDefault(true);
  ui->sizeLineEdit->clearFocus();
  ui->pushButton->setFocus();
}
bool FindForm::eventFilter(QObject* obj, QEvent* event) {
  if (event->type() == QEvent::FocusIn) {
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(QApplication::focusWidget());
    QPushButton* button = qobject_cast<QPushButton*>(QApplication::focusWidget());
    if (lineEdit == ui->modelLineEdit) {
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
