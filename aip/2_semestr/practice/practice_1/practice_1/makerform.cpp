#include "makerform.h"
#include "ui_makerform.h"
#include "widget.h"
#include <QMessageBox>

MakerForm::MakerForm(void* par, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MakerForm), parentForm(par) {
  ui->setupUi(this);
  ui->pushButton->setAutoDefault(false);
  ui->pushButton_3->setAutoDefault(false);
  ui->makerLineEdit->installEventFilter(this);
  ui->pushButton->installEventFilter(this);
  ui->pushButton_3->installEventFilter(this);
  setWindowTitle("Поиск обуви у производителя");
}

MakerForm::~MakerForm() {
  delete ui;
}

void MakerForm::on_pushButton_clicked() {
  if (!ui->makerLineEdit->text().isEmpty()) {
    ((Widget*) parentForm)->updateDataBase();
    auto maker = ui->makerLineEdit->text();
    auto temp = QString("");
    ((Widget*) parentForm)->showFindedDataBase(maker, temp);
  } else {
      QMessageBox::critical(this, "Ошибка", "Введите производителя");
    }
}

void MakerForm::on_makerLineEdit_returnPressed() {
  ui->pushButton->setAutoDefault(true);
  ui->pushButton_3->setAutoDefault(true);
  ui->makerLineEdit->clearFocus();
  ui->pushButton->setFocus();
}
bool MakerForm::eventFilter(QObject* obj, QEvent* event) {
  if (event->type() == QEvent::FocusIn) {
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(QApplication::focusWidget());
    QPushButton* button = qobject_cast<QPushButton*>(QApplication::focusWidget());
    if (lineEdit == ui->makerLineEdit) {
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
