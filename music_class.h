#ifndef MUSIC_CLASS_H_
#define MUSIC_CLASS_H_

#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMultimedia>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "settings_dialog.h"

class MusicClass : public QWidget {
  Q_OBJECT
 public:
  explicit MusicClass(QWidget* parent = nullptr);

  QMediaPlayer* GetPlayer();
  QMediaPlaylist* GetPlaylist();

  void CreateDialog();

 private:
  inline static const QString kMusicDirPath = "./resources/music";

  QMediaPlayer* media_player_;
  QMediaPlaylist* media_playlist_;

  QDir GetMusicDir();
  bool IsMusicDirExists() const;
};

#endif  // MUSIC_CLASS_H_
