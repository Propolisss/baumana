#ifndef ADDFORM_H
#define ADDFORM_H

#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class AddForm;
}

class AddForm : public QDialog {
 Q_OBJECT

 public:
  explicit AddForm(void* par, QWidget* parent = nullptr);
  ~AddForm() override;

 private slots:
  void on_pushButton_clicked();

  void on_surnameLineEdit_returnPressed();

  void on_nameLineEdit_returnPressed();

  void on_phoneLineEdit_returnPressed();

  void on_adressLineEdit_returnPressed();

  bool eventFilter(QObject* obj, QEvent* event) override;
 private:
  Ui::AddForm* ui;
  void* parentForm;
};

#endif // ADDFORM_H
