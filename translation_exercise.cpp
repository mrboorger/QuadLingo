#include "translation_exercise.h"

TranslationExercise::TranslationExercise(QWidget* parent) : ExerciseWidget(
    parent) {
  answer_ = new QTextEdit(this);
  answer_->setPlaceholderText(tr("Write a translation here"));

  task_label_->setText("Translate this sentence");

  sentence_label_->setWordWrap(true);

  answer_->setSizePolicy(QSizePolicy::Expanding,
                         QSizePolicy::Expanding);

  submit_button_->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);

  // answer_->setAutoFormatting(QTextEdit::AutoAll);


  layout_->addWidget(task_label_, 1);

  layout_->addWidget(sentence_label_, 2);

  layout_->addWidget(answer_, 3);

  layout_->addWidget(submit_button_, 1);

  layout_->addWidget(progress_bar_, 1);

  progress_bar_->setMaximum(count_questions_); ////

  connect(submit_button_, &QPushButton::clicked,
          this, &TranslationExercise::CheckAnswerAndToNextPart);

  setLayout(layout_);
  GenerateNewExercise();
}

void TranslationExercise::GGLoadSentences() {
  exercises_.push_back({tr("Make America Great again"),
                        tr("Сделать Америку снова Великой")});
  exercises_.push_back({tr("You need to buy two apples"),
                        tr("Вам нужно купить два яблока")});
  exercises_.push_back({tr("Make America Great again"),
                        tr("Сделать Америку снова Великой")});
  exercises_.push_back({tr("You need to buy two apples"),
                        tr("Вам нужно купить два яблока")});
  exercises_.push_back({tr("Make America Great again"),
                        tr("Сделать Америку снова Великой")});
}

void TranslationExercise::GenerateNewExercise() {
  exercises_.clear();
  count_incorrect_ = 0;
  cur_num_question_ = 0;

  exercise_timer_->setSingleShot(true);
  exercise_timer_->setInterval(time_to_solve_);
  exercise_timer_->start();

  // GGLoadSentences();
  exercises_ =
      TasksLoader::LoadTranslation(count_questions_, difficulty_level_);
  GenerateNextPart();
}

bool TranslationExercise::CheckAnswer() {
  if (exercises_[cur_num_question_ - 1].second.toLower()
      != answer_->toPlainText().toLower()) {
    // IncIncorrect() --
    return IncIncorrect();
  }
  return false;
}

void TranslationExercise::GenerateNextPart() {
  progress_bar_->setValue(cur_num_question_);
  sentence_label_->setText(exercises_[cur_num_question_++].first);
  answer_->setText(tr(""));
}


