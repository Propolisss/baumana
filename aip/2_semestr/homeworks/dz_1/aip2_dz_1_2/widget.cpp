#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include <QRadioButton>
#include <Qt>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <QString>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  frame = new QFrame();
  countWidgets = -1000;
  updateDataBase();
  ui->scrollArea->setWidget(frame);
  connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteRecord()));
}

Widget::~Widget() {
  delete ui;
}

void Widget::on_pushButton_clicked() {
  addForm = new AddForm(this);
  addForm->show();
}

void Widget::on_pushButton_2_clicked() {
  findForm = new FindForm(this);
  findForm->show();
}

void Widget::setDataBase(QString& surname_, QString& name_, QString& phone_, QString& adress_) {
  QFrame* tempFrame = new QFrame(frame);
  tempFrame->setMaximumHeight(50);
  tempFrame->setMinimumHeight(50);
  QHBoxLayout* horLayout = new QHBoxLayout(tempFrame);

  QRadioButton* radioButton = new QRadioButton(frame);
  radioButton->setMaximumWidth(20);
  horLayout->addWidget(radioButton);
  QFrame* frame1 = new QFrame(tempFrame);
  frame1->setMaximumHeight(50);
  QLabel* label1 = new QLabel(frame1);
  label1->setText(surname_);
  horLayout->addWidget(frame1);

  QFrame* frame2 = new QFrame(tempFrame);
  frame2->setMaximumHeight(50);
  QLabel* label2 = new QLabel(frame2);
  label2->setText(name_);
  horLayout->addWidget(frame2);

  QFrame* frame3 = new QFrame(tempFrame);
  frame3->setMaximumHeight(50);
  QLabel* label3 = new QLabel(frame3);
  label3->setText(phone_);
  horLayout->addWidget(frame3);

  QFrame* frame4 = new QFrame(tempFrame);
  frame4->setMaximumHeight(50);
  QLabel* label4 = new QLabel(frame4);
  label4->setText(adress_);
  horLayout->addWidget(frame4);
  vertLayout->insertWidget(countWidgets++, tempFrame);
  std::vector<QString> temp = {surname_, name_, phone_, adress_};
  arrRadioButtons.push_back(std::make_pair(temp, radioButton));
}

void Widget::updateDataBase() {
  if (countWidgets != -1000) {
    for (int i = 0; i < countWidgets; ++i) {
      QLayoutItem* item = vertLayout->itemAt(0);
      vertLayout->removeItem(item);
      QWidget* widget = item->widget();
      vertLayout->removeWidget(widget);
      delete widget;
      delete item;
    }
  } else {
    vertLayout = new QVBoxLayout(frame);
  }
  arrRadioButtons.clear();
  countWidgets = 0;
  std::fstream out;
  out.open("..//data_base.txt", std::ios::in);
  std::string surname;
  std::string name;
  std::string phone;
  std::string adress;

  while (std::getline(out, surname), std::getline(out, name),
      std::getline(out, phone), std::getline(out, adress)) {
    setDataBase((QString&) std::move(QString(surname.c_str())), (QString&) std::move(QString(name.c_str())),
                (QString&) std::move(QString(phone.c_str())), (QString&) std::move(QString(adress.c_str())));
  }

  vertLayout->addStretch();
  out.close();
}

void Widget::deleteRecord() {
  for (int i = 0; i < countWidgets; ++i) {
    QLayoutItem* item = vertLayout->itemAt(i);
    if (arrRadioButtons[i].second->isChecked()) {
      //indexes[i] = true;
      vertLayout->removeItem(item);
      QWidget* widget = item->widget();
      vertLayout->removeWidget(widget);
      delete widget;
      delete item;
      deleteDataBase(arrRadioButtons[i].first[0], arrRadioButtons[i].first[1],
                     arrRadioButtons[i].first[2], arrRadioButtons[i].first[3]);
      arrRadioButtons.erase(arrRadioButtons.begin() + i);
      --i;
      --countWidgets;
    }
  }
}
void Widget::deleteDataBase(QString& surname_, QString& name_, QString& phone_, QString& adress_) {
  std::fstream out;
  std::fstream in("..//data_base_2.txt", std::ios::out);
  out.open("..//data_base.txt", std::ios::in);
  bool flag = false;
  auto size = sizeOfFile() / 4;
  for (int i = 0; i < size; ++i) {
    std::string surname;
    std::string name;
    std::string phone;
    std::string adress;
    std::getline(out, surname);
    std::getline(out, name);
    std::getline(out, phone);
    std::getline(out, adress);
    if (surname_.toStdString() == surname && name_.toStdString() == name &&
        phone == phone_.toStdString() && adress == adress_.toStdString() && !flag) {
      flag = true;
      continue;
    } else {
      if (surname.empty()) {
        continue;
      }
      in << surname + '\n';
      in << name + '\n';
      in << phone + '\n';
      in << adress + '\n';
    }
  }

  out.close();
  in.close();
  remove("..//data_base.txt");
  rename("..//data_base_2.txt", "..//data_base.txt");
}
void Widget::showFindedDataBase(QString& surname_, QString& name_, QString& phone_, QString& adress_) {
  for (int i = 0; i < countWidgets; ++i) {
    QLayoutItem* item = vertLayout->itemAt(i);
    if (!((arrRadioButtons[i].first[0] == surname_ || arrRadioButtons[i].first[1] == name_) &&
        arrRadioButtons[i].first[2] == phone_ && arrRadioButtons[i].first[3] == adress_)) {
      //indexes[i] = true;
      vertLayout->removeItem(item);
      QWidget* widget = item->widget();
      vertLayout->removeWidget(widget);
      delete widget;
      delete item;
      //deleteDataBase(arrRadioButtons[i].first[0], arrRadioButtons[i].first[1],
      //               arrRadioButtons[i].first[2], arrRadioButtons[i].first[3]);
      arrRadioButtons.erase(arrRadioButtons.begin() + i);
      --i;
      --countWidgets;
    }
  }
}

void Widget::on_pushButton_4_clicked() {
  updateDataBase();
}

int Widget::sizeOfFile() {
  std::fstream out;
  out.open("..//data_base.txt", std::ios::in);
  int size;
  std::string temp;
  while (std::getline(out, temp)) {
    ++size;
  }
  return size;
}

