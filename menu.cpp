#include "menu.h"

Menu::Menu(QWidget* parent) : score_label_(new QLabel("Score: 0 ")) {
  setParent(parent);
  auto* menu = new QMenu(tr("Menu"));
  auto* change_difficulty(new QAction(tr("&Change difficulty"), this));
  menu->addAction(change_difficulty);
  connect(change_difficulty, &QAction::triggered, this, &Menu::ShowDialog);
  // connect(change_difficulty, &QAction::triggered, qApp, &QApplication::quit);
  // menu->addAction("&Change difficulty",
  //                          qApp,
  //                          &aboutQt(),
  //                          Qt::CTRL + Qt::Key_C
  // );
  addMenu(menu);
  this->setCornerWidget(score_label_);
}

void Menu::ShowDialog() {
  // auto* dialog(new DifficultyDialog);
  // dialog->show();
  // if (dialog->exec() == QDialog::Accepted) {
  //   ChangeDifficulty();
  // } else {
  //
  // }
  // delete dialog;
}

void Menu::ChangeDifficulty() {

}
