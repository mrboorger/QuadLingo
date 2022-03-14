#ifndef MENU_H_
#define MENU_H_

#include <QAction>
#include <QApplication>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QSizePolicy>
#include <QWidget>
#include <iostream>

#include "difficulty_dialog.h"
#include "music_class.h"
#include "settings_dialog.h"

class Menu : public QMenuBar {
  Q_OBJECT
 public:
  explicit Menu(QWidget* parent = nullptr);

  void ShowDialog();
  void IncScore();

 signals:
  void ChangeDifficultySignal(int level);

 private:
  int cur_level_ = 0;

  int score_ = 0;
  QLabel* score_label_;
  MusicClass* music_class_;
};

#endif  // MENU_H_
