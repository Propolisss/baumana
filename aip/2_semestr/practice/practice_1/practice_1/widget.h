#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "addform.h"
#include "findform.h"
#include "QFrame"
#include "makerform.h"
#include "modelform.h"
#include <vector>
#include <QRadioButton>
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT

 public:
  explicit Widget(QWidget* parent = nullptr);
  ~Widget() override;
  void setDataBase(QString&, QString&, QString&, QString&, bool);
  void updateDataBase();
  void deleteDataBase(QString&, QString&, QString&, QString&);
  void showFindedDataBase(QString&, QString&);
  void keyPressEvent(QKeyEvent* event) override;
  void showChart(const QString&);

 private slots:
  void deleteRecord();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_6_clicked();

  void on_deleteButton_clicked();

private:
  Ui::Widget* ui;
  FindForm* findForm;
  AddForm* addForm;
  QVBoxLayout* vertLayout;
  QFrame* frame;
  MakerForm* makerForm;
  ModelForm* modelForm;
  int countWidgets;
  std::vector<std::pair<std::vector<QString>, QRadioButton*>> arrRadioButtons;
  int sizeOfFile();
  bool isUpdated = false;
};
#endif // WIDGET_H
