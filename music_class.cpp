#include "music_class.h"

MusicClass::MusicClass(QWidget* parent)
    : QWidget(parent),
      media_player_(new QMediaPlayer(this)),
      media_playlist_(new QMediaPlaylist(this)) {
  media_playlist_->setPlaybackMode(QMediaPlaylist::Loop);
  QDir directory;

  try {
    directory = GetMusicDir();
  } catch (std::runtime_error& e) {
    qDebug() << e.what() << '\n';
    return;
  }

  QStringList music_list = directory.entryList(QStringList() << "*.mp3"
                                                             << "*.MP3",
                                               QDir::Files);

  for (const auto& music_name : music_list) {
    media_playlist_->addMedia(QUrl::fromLocalFile(directory.absolutePath() + "/" + music_name));
  }

  media_player_->setPlaylist(media_playlist_);
  media_player_->setMedia(media_playlist_);
}

QMediaPlayer* MusicClass::GetPlayer() { return media_player_; }

QMediaPlaylist* MusicClass::GetPlaylist() { return media_playlist_; }

void MusicClass::CreateDialog() {
  auto* dialog(new SettingsDialog(this));
  dialog->exec();
}

bool MusicClass::IsMusicDirExists() const {
  const QFileInfo music_dir_info(kMusicDirPath);
  return music_dir_info.exists() && music_dir_info.isDir();
}

QDir MusicClass::GetMusicDir() {
  if (!IsMusicDirExists()) {
    throw std::runtime_error("Directory \"" + kMusicDirPath.toStdString() + "\"" +
                             " doesn't exist\n");
  }
  return QDir(kMusicDirPath);
}
