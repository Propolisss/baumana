#ifndef MODELFORM_H
#define MODELFORM_H

#include <QDialog>

namespace Ui {
  class ModelForm;
}

class ModelForm : public QDialog
{
  Q_OBJECT

public:
  explicit ModelForm(void* par, QWidget *parent = nullptr);
  ~ModelForm();

private slots:
  void on_pushButton_clicked();

  void on_modelLineEdit_returnPressed();

  bool eventFilter(QObject* obj, QEvent* event) override;
private:
  Ui::ModelForm *ui;
  void* parentForm;
};

#endif // MODELFORM_H
