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

 private:
  Ui::AddForm* ui;
  void* parentForm;
};

#endif // ADDFORM_H
