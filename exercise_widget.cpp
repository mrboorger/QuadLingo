#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent, int level) :
    QWidget(parent),
    exercise_timer_(new QTimer(this)),
    layout_(new QVBoxLayout(this)),
    task_label_(new QLabel(this)),
    sentence_label_(new QLabel(this)),
    submit_button_(new QPushButton("Submit", this)),
    progress_bar_(new QProgressBar(this)) {
  // Centr
  difficulty_level_ = level;
  task_label_->setWordWrap(true);
  sentence_label_->setWordWrap(true);
  connect(exercise_timer_, &QTimer::timeout,
          this, &ExerciseWidget::RestartTimeOut);
}

void ExerciseWidget::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_H) {
    ShowTip();
  }
}

void ExerciseWidget::CheckAnswerAndToNextPart() {
  bool is_restart = CheckAnswer();
  if (cur_num_question_ < count_questions_) {
    if (!is_restart) {
      GenerateNextPart();
    }
  } else {
    if (count_incorrect_ == 0) {
      emit(IncScoreSignal());
    }
    GenerateNewExercise();
  }
}

// return true, when RestartFail called;
bool ExerciseWidget::IncIncorrect() {
  ++count_incorrect_;
  if (count_incorrect_ == max_wrong_) {
    RestartFail();
    return true;
  }
  return false;
}

void ExerciseWidget::RestartFail() {
  auto* wrong_dialog(new QDialog(this));
  wrong_dialog->setWindowTitle("Wrong!");
  // wrong_dialog->setSizePolicy(QSizePolicy::Expanding,
  //                             QSizePolicy::Expanding);
  auto* label(new QLabel(tr("Too many incorrect answers")));
  label->setWordWrap(true);
  auto* button(new QPushButton("Restart"));
  auto* layout(new QVBoxLayout(wrong_dialog));
  label->setSizePolicy(QSizePolicy::Expanding,
                       QSizePolicy::Expanding);
  button->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  layout->addWidget(label, 3);
  layout->addWidget(button, 1);
  wrong_dialog->resize(300, 100);
  connect(button, &QPushButton::clicked, wrong_dialog, &QDialog::reject);
  connect(wrong_dialog, &QDialog::rejected,
          this, &ExerciseWidget::GenerateNewExercise);
  wrong_dialog->exec();
}

void ExerciseWidget::ShowTip() {
  exercise_timer_->stop();
  dialog_tip_ = new QDialog(this);
  auto* tip_layout(new QVBoxLayout(dialog_tip_));
  auto* label_tip(new QLabel(cur_tip_));
  auto* ok_button(new QPushButton("OK"));
  label_tip->setSizePolicy(QSizePolicy::Expanding,
                           QSizePolicy::Expanding);
  ok_button->setSizePolicy(QSizePolicy::Expanding,
                           QSizePolicy::Expanding);
  label_tip->setWordWrap(true);
  tip_layout->addWidget(label_tip, 3);
  tip_layout->addWidget(ok_button, 1);

  dialog_tip_->setLayout(tip_layout);
  dialog_tip_->resize(400, 200);
  connect(ok_button, &QPushButton::clicked, dialog_tip_, &QDialog::reject);
  dialog_tip_->exec();
}

void ExerciseWidget::RestartTimeOut() {
  if (dialog_tip_ != nullptr) {
    dialog_tip_->reject();
  }
  auto* wrong_dialog(new QDialog(this));
  wrong_dialog->setWindowTitle("Time Out!");
  wrong_dialog->setSizePolicy(QSizePolicy::Expanding,
                              QSizePolicy::Expanding);
  auto* label(new QLabel(tr("Too slow")));
  label->setWordWrap(true);
  auto* button(new QPushButton("Restart"));
  auto* layout(new QVBoxLayout(wrong_dialog));
  label->setSizePolicy(QSizePolicy::Expanding,
                       QSizePolicy::Expanding);
  button->setSizePolicy(QSizePolicy::Expanding,
                        QSizePolicy::Expanding);
  layout->addWidget(label, 3);
  layout->addWidget(button, 1);

  wrong_dialog->resize(300, 100);
  connect(button, &QPushButton::clicked, wrong_dialog, &QDialog::reject);
  connect(wrong_dialog, &QDialog::rejected,
          this, &ExerciseWidget::GenerateNewExercise);
  wrong_dialog->exec();
}

void ExerciseWidget::ChangeDifficulty(int level) {
  difficulty_level_ = level;
  GenerateNewExercise();
}
// add buffer class
