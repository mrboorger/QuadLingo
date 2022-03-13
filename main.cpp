#include <QApplication>
#include <QStyleFactory>

#include <iostream>

#include "main_window.h"


int main(int argc, char* argv[]) {
  srand(time(0));
  QApplication application(argc, argv);
  application.setStyle(QStyleFactory::create("Fusion"));
  MainWindow win;
  win.setWindowTitle("QuadLingo");
  win.show();

  return QApplication::exec();
}
