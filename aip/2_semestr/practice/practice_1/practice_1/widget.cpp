#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>
#include <QRadioButton>
#include <Qt>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <QString>
#include <unordered_map>
#include <QtCharts>
#include <algorithm>

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  frame = new QFrame();
  countWidgets = -1000;
  setWindowTitle("Обувной магазин");
  updateDataBase();
  ui->scrollArea->setWidget(frame);
  connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteRecord()));
}

Widget::~Widget() {
  delete ui;
}

void Widget::on_pushButton_clicked() {
  ui->label_2->setText("Размер");
  updateDataBase();
  isUpdated = true;
  addForm = new AddForm(this, this);
  addForm->show();
}

void Widget::on_pushButton_2_clicked() {
  ui->label_2->setText("Размер");
  updateDataBase();
  isUpdated = false;
  findForm = new FindForm(this, this);
  findForm->show();
}

void Widget::setDataBase(QString& surname_, QString& name_, QString& phone_, QString& adress_, bool flag) {
  QFrame* tempFrame = new QFrame(frame);
  tempFrame->setMaximumHeight(50);
  tempFrame->setMinimumHeight(50);
  QHBoxLayout* horLayout = new QHBoxLayout(tempFrame);

  QRadioButton* radioButton = new QRadioButton(frame);
  radioButton->setMaximumWidth(20);
  if (flag) {
    horLayout->addWidget(radioButton);
  }
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
  arrRadioButtons.emplace_back(temp, radioButton);
}

void Widget::updateDataBase() {
  if (isUpdated) {
      return;
    }
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
  isUpdated = true;
  arrRadioButtons.clear();
  countWidgets = 0;
  std::fstream out;
  out.open("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base.txt",
           std::ios::in);
  std::string surname;
  std::string name;
  std::string phone;
  std::string adress;

  while (std::getline(out, surname), std::getline(out, name),
      std::getline(out, phone), std::getline(out, adress)) {
    setDataBase((QString&) std::move(QString(surname.c_str())), (QString&) std::move(QString(name.c_str())),
                (QString&) std::move(QString(phone.c_str())), (QString&) std::move(QString(adress.c_str())), true);
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
  std::fstream in
      ("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base_2.txt", std::ios::out);
  out.open("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base.txt",
           std::ios::in);
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
  remove("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base.txt");
  rename("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base_2.txt",
         "//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base.txt");
}
void Widget::showFindedDataBase(QString& model_, QString& size_) {
  for (int i = 0; i < countWidgets; ++i) {
    QLayoutItem* item = vertLayout->itemAt(i);
    if (((arrRadioButtons[i].first[0].toLower() != model_.toLower()
        || arrRadioButtons[i].first[2].toLower() != size_.toLower())
        && !size_.isEmpty())
        || (arrRadioButtons[i].first[1].toLower() != model_.toLower() && size_.isEmpty())) {
      vertLayout->removeItem(item);
      QWidget* widget = item->widget();
      vertLayout->removeWidget(widget);
      delete widget;
      delete item;
      arrRadioButtons.erase(arrRadioButtons.begin() + i);
      --i;
      --countWidgets;
    }
  }
  isUpdated = false;
}

void Widget::on_pushButton_4_clicked() {
  updateDataBase();
  ui->label_2->setText("Количество моделей");
  isUpdated = false;
  std::unordered_map<QString, std::unordered_map<QString, size_t>> makers;
  for (int i = 0; i < countWidgets; ++i) {
    makers[arrRadioButtons[i].first[1]][arrRadioButtons[i].first[0]] += arrRadioButtons[i].first[3].toInt();
    QLayoutItem* item = vertLayout->itemAt(i);
    vertLayout->removeItem(item);
    QWidget* widget = item->widget();
    vertLayout->removeWidget(widget);
    delete widget;
    delete item;
    arrRadioButtons.erase(arrRadioButtons.begin() + i);
    --i;
    --countWidgets;
  }
  for (auto& pair : makers) {
    size_t summ = 0;
    for (auto pair2 : pair.second) {
      summ += pair2.second;
    }
    auto temp = QString();
    auto maker = pair.first;
    auto models = QString::number(pair.second.size());
    auto qsumm = QString::number(summ);
    setDataBase(temp, maker, models, qsumm, false);
  }
}

int Widget::sizeOfFile() {
  std::fstream out;
  out.open("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base.txt",
           std::ios::in);
  int size;
  std::string temp;
  while (std::getline(out, temp)) {
    ++size;
  }
  return size;
}
void Widget::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    QRadioButton* button = qobject_cast<QRadioButton*>(QApplication::focusWidget());
    if (button) {
      button->setChecked(true);
    }
  }

  QWidget::keyPressEvent(event);
}

void Widget::on_pushButton_5_clicked() {
  ui->label_2->setText("Размер");
  isUpdated = false;
  for (int i = 0; i < countWidgets; ++i) {
    QLayoutItem* item = vertLayout->itemAt(i);
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
  std::ofstream file("//home//propolisss//baumana//aip//2_semestr//practice//practice_1//practice_1//data_base.txt");
  file.close();
}

void Widget::on_pushButton_7_clicked() {
  ui->label_2->setText("Размер");
  updateDataBase();
  isUpdated = true;
  makerForm = new MakerForm(this, this);
  makerForm->show();
}

void Widget::on_pushButton_8_clicked() {
  ui->label_2->setText("Размер");
  updateDataBase();
  isUpdated = true;

}

void Widget::on_pushButton_6_clicked() {
  ui->label_2->setText("Размер");
  updateDataBase();
  isUpdated = true;

  modelForm = new ModelForm(this, this);
  modelForm->show();
}

void Widget::showChart(const QString& model_) {
  int minx = 10e7, maxx = -1, miny = 10e7, maxy = -1;
  std::unordered_map<QString, std::map<int, int>> models;
  for (size_t i = 0; i < countWidgets; ++i) {
      models[arrRadioButtons[i].first[0]][arrRadioButtons[i].first[2].toInt()] +=
          arrRadioButtons[i].first[3].toInt();
  }
  try {
    models.at(model_);
  } catch(...) {
    QMessageBox::critical(this, "Ошибка", "Нет такой модели");
    return;
  }

  QChart* chart = new QChart();
  chart->setTitle("Зависимость количества пар обуви от размера");
  std::vector<std::pair<int, int>> pairs;
  QLineSeries* series = new QLineSeries();
  for (auto& pair : models[model_]) {
      minx = std::min(minx, pair.first);
      maxx = std::max(maxx, pair.first);
      miny = std::min(miny, pair.second);
      maxy = std::max(maxy, pair.second);
      series->append(pair.first, pair.second);
  }

  chart->addSeries(series);

  QValueAxis* axisX = new QValueAxis();
  axisX->setTitleText("Размер обуви");
  axisX->setTickCount(maxx - minx + 1);
  axisX->setTickInterval(1);
  chart->addAxis(axisX, Qt::AlignBottom);
  series->attachAxis(axisX);

  QValueAxis* axisY = new QValueAxis();
  axisY->setTitleText("Количество пар");
  axisY->setTickCount(maxy - miny + 1);
  axisY->setTickInterval(1);
  chart->addAxis(axisY, Qt::AlignLeft);
  series->attachAxis(axisY);


  QChartView* chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->resize(600, 600);
  chartView->show();
}

void Widget::on_deleteButton_clicked()
{
    isUpdated = false;
}

