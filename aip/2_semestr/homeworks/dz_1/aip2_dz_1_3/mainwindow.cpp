#include <QVBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle("Обработка событий");
  resize(700, 700);

  area = new Area(this);
  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(area);

  QWidget* centralWidget = new QWidget(this);
  centralWidget->setLayout(layout);
  setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() = default;

