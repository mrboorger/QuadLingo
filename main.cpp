#include <QApplication>
#include <QStyleFactory>

#include <iostream>

#include "main_window.h"


int main(int argc, char* argv[]) {
  srand(time(0));
  QApplication application(argc, argv);
  application.setStyle(QStyleFactory::create("Fusion"));
  for(auto kek : QStyleFactory::keys()) {
    std::cerr << kek.toStdString() << std::endl;
  }
  MainWindow win;
  win.setWindowTitle("Dancing With Sum");
  win.show();

  return QApplication::exec();
}
