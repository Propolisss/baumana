#ifndef FINDFORM_H
#define FINDFORM_H

#include <QDialog>

namespace Ui {
class FindForm;
}

class FindForm : public QDialog {
 Q_OBJECT

 public:
  explicit FindForm(void* par, QWidget* parent = nullptr);
  ~FindForm() override;

private slots:
  void on_pushButton_clicked();

  void on_sizeLineEdit_returnPressed();

  void on_modelLineEdit_returnPressed();

  bool eventFilter(QObject* obj, QEvent* event) override;

private:
  Ui::FindForm* ui;
  void* parentForm;
};

#endif // FINDFORM_H