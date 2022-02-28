#include <QApplication>
#include <QStyleFactory>

#include <iostream>

#include "main_window.h"


int main(int argc, char* argv[]) {
  srand(time(0));
  QApplication application(argc, argv);
  application.setStyle(QStyleFactory::create("Fusion"));
  // for(auto kek : QStyleFactory::keys()) {
  //   std::cerr << kek.toStdString() << std::endl;
  // }
  MainWindow win;
  win.setWindowTitle("QuadLingo");
//  win.setWindowIcon(QIcon("c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\quad.jpg"));
  win.show();

  return QApplication::exec();
}
