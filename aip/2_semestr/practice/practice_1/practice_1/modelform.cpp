#include "modelform.h"
#include "ui_modelform.h"
#include "widget.h"
#include <QMessageBox>

ModelForm::ModelForm(void* par, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ModelForm), parentForm(par)
{
  ui->setupUi(this);
  ui->pushButton->setAutoDefault(false);
  ui->pushButton_3->setAutoDefault(false);
  ui->modelLineEdit->installEventFilter(this);
  ui->pushButton->installEventFilter(this);
  ui->pushButton_3->installEventFilter(this);
  setWindowTitle("Построение графика модели обуви");
}

ModelForm::~ModelForm()
{
  delete ui;
}


void ModelForm::on_pushButton_clicked() {
  if (!ui->modelLineEdit->text().isEmpty()) {
    auto model = ui->modelLineEdit->text();
    ((Widget*) parentForm)->showChart(model);
  } else {
      QMessageBox::critical(this, "Ошибка", "Введите модель");
 }
}

void ModelForm::on_modelLineEdit_returnPressed() {
  ui->pushButton->setAutoDefault(true);
  ui->pushButton_3->setAutoDefault(true);
  ui->modelLineEdit->clearFocus();
  ui->pushButton->setFocus();
}
bool ModelForm::eventFilter(QObject* obj, QEvent* event) {
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
