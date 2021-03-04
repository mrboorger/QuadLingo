#ifndef MUSIC_CLASS_H_
#define MUSIC_CLASS_H_

#include <QWidget>
#include <QMultimedia>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "settings_dialog.h"

class MusicClass : public QWidget {
  Q_OBJECT
 public:
  explicit MusicClass(QWidget* parent = nullptr);

  QMediaPlayer* GetPlayer();
  QMediaPlaylist* GetPlaylist();

  void CreateDialog();
 private:
  QMediaPlayer* media_player_;

  QMediaPlaylist* media_playlist_;

};

#endif  // MUSIC_CLASS_H_
