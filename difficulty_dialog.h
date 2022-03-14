#ifndef DIFFICULTY_DIALOG_H_
#define DIFFICULTY_DIALOG_H_

#include <QApplication>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>

class DifficultyDialog : public QDialog {
  Q_OBJECT
 public:
  explicit DifficultyDialog(QWidget* parent = nullptr, int cur_level = 0);

  int GetNumChecked();

 private:
  QGroupBox* buttons_;
  QVBoxLayout* layout_;
  QDialogButtonBox* dialog_buttons_;

  QVector<QRadioButton*> difficulty_buttons_;
};

#endif  // DIFFICULTY_DIALOG_H
