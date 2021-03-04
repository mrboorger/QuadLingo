#include "difficulty_dialog.h"

DifficultyDialog::DifficultyDialog(QWidget* parent, int cur_level) :
    QDialog(parent),
    buttons_(new QGroupBox()),
    layout_(new QVBoxLayout(this)),
    dialog_buttons_(new QDialogButtonBox()),
    difficulty_buttons_() {
  auto* easy_button_(new QRadioButton(tr("Easy")));
  auto* medium_button_(new QRadioButton(tr("Medium")));
  auto* hard_button_(new QRadioButton(tr("Hard")));

  difficulty_buttons_.append(easy_button_);
  difficulty_buttons_.append(medium_button_);
  difficulty_buttons_.append(hard_button_);

  difficulty_buttons_[cur_level]->setChecked(true);

  auto* vert_box(new QVBoxLayout);

  for (auto i : difficulty_buttons_) {
    vert_box->addWidget(i);
  }
  buttons_->setLayout(vert_box);

  layout_->addWidget(buttons_);
  dialog_buttons_->addButton(tr("Accept"), QDialogButtonBox::ButtonRole::AcceptRole);
  dialog_buttons_->addButton(tr("Close"), QDialogButtonBox::ButtonRole::RejectRole);
  layout_->addWidget(dialog_buttons_);


  connect(dialog_buttons_, &QDialogButtonBox::accepted, this, &QDialog::accept);
  connect(dialog_buttons_, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

int DifficultyDialog::GetNumChecked() {
  for (int i = 0; i < difficulty_buttons_.size(); ++i) {
    if (difficulty_buttons_[i]->isChecked()) {
      return i;
    }
  }
}
