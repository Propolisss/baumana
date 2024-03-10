#include <QApplication>
#include "Win.h++"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Win win;
  win.show();

  return app.exec(); // запускаем цикл обработки сообщений
}