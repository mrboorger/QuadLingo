#include "music_class.h"

MusicClass::MusicClass(QWidget* parent)
    : QWidget(parent),
      media_player_(new QMediaPlayer(this)),
      media_playlist_(new QMediaPlaylist(this)) {
  media_playlist_->setPlaybackMode(QMediaPlaylist::Loop);
//  media_playlist_->addMedia(QUrl::fromLocalFile(
//      "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\music\\music.mp3"));
//  media_playlist_->addMedia(QUrl::fromLocalFile(
//      "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\music\\music0.mp3"));
//  media_playlist_->addMedia(QUrl::fromLocalFile(
//      "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\music\\music2.mp3"));
//  media_playlist_->addMedia(QUrl::fromLocalFile(
//      "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\music\\music3.mp3"));
//  media_playlist_->addMedia(QUrl::fromLocalFile(
//      "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\music\\.mp3"));

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
  auto* dialog(new SettingsDialog(this));
  dialog->exec();
}

