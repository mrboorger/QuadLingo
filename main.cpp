#include <QApplication>

#include "main_window.h"


int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  // CentralWidget cw(nullptr);
  // cw.ChangeToTranslation();
  // cw.show();
  MainWindow win;
  win.setWindowTitle("Dancing With Sum");
  win.show();

  return QApplication::exec();
}
