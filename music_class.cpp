#include "music_class.h"

MusicClass::MusicClass(QWidget* parent)
    : QWidget(parent),
      media_player_(new QMediaPlayer()),
      media_playlist_(new QMediaPlaylist()) {
  // SetUi();

  // settings_->setSizePolicy(QSizePolicy::Expanding,
  //                       QSizePolicy::Expanding);
  // QIcon icon("c:\\Users\\mrboorger\\CLionProjects\\QT_SEM_MULTIMEDIA\\cmake-build-debug\\photo.jpg");
  // settings_->setIcon(QIcon("c:\\Users\\mrboorger\\CLionProjects\\QT_SEM_MULTIMEDIA\\cmake-build-debug\\photo.jpg"));
  // settings_->setIconSize(QSize(100, 100));

  media_playlist_->setPlaybackMode(QMediaPlaylist::Loop);
  media_playlist_->addMedia(QUrl::fromLocalFile(
      "c:\\Users\\mrboorger\\CLionProjects\\QT_SEM_MULTIMEDIA\\cmake-build-debug\\music.mp3"));
  media_playlist_->addMedia(QUrl::fromLocalFile(
      "c:\\Users\\mrboorger\\CLionProjects\\QT_SEM_MULTIMEDIA\\cmake-build-debug\\music2.mp3"));
  media_playlist_->addMedia(QUrl::fromLocalFile(
      "c:\\Users\\mrboorger\\CLionProjects\\QT_SEM_MULTIMEDIA\\cmake-build-debug\\music3.mp3"));
  media_playlist_->addMedia(QUrl::fromLocalFile(
      "c:\\Users\\mrboorger\\CLionProjects\\QT_SEM_MULTIMEDIA\\cmake-build-debug\\music4.mp3"));

  media_player_->setPlaylist(media_playlist_);
  media_player_->setMedia(media_playlist_);
}

QMediaPlayer* MusicClass::GetPlayer() {
  return media_player_;
}

QMediaPlaylist* MusicClass::GetPlaylist() {
  return media_playlist_;
}

void MusicClass::CreateDialog() {
  SettingsDialog* dialog(new SettingsDialog(this));
  dialog->exec();
}

