#ifndef MAKERFORM_H
#define MAKERFORM_H

#include <QDialog>

namespace Ui {
  class MakerForm;
}

class MakerForm : public QDialog
{
  Q_OBJECT

public:
  explicit MakerForm(void* par, QWidget *parent = nullptr);
  ~MakerForm();

private slots:
  void on_pushButton_clicked();

  void on_makerLineEdit_returnPressed();

  bool eventFilter(QObject* obj, QEvent* event) override;
private:
  Ui::MakerForm *ui;
  void* parentForm;
};

#endif // MAKERFORM_H
