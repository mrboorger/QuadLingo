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
  sentences_.push_back(tr("Make America Great again"));
  translated_.push_back(tr("Сделать Америку снова Великой"));

  sentences_.push_back(tr("You need to buy two apples"));
  translated_.push_back(tr("Вам нужно купить два яблока"));

  sentences_.push_back(tr("Make America Great again"));
  translated_.push_back(tr("Сделать Америку снова Великой"));

  sentences_.push_back(tr("You need to buy two apples"));
  translated_.push_back(tr("Вам нужно купить два яблока"));

  sentences_.push_back(tr("Make America Great again"));
  translated_.push_back(tr("Сделать Америку снова Великой"));
}

void TranslationExercise::GenerateNewExercise() {
  sentences_.clear();
  translated_.clear();
  count_incorrect_ = 0;
  cur_num_question_ = 0;

  exercise_timer_->setSingleShot(true);
  exercise_timer_->setInterval(time_to_solve_);
  exercise_timer_->start();

  GGLoadSentences();
  GenerateNextPart();
}

void TranslationExercise::CheckAnswerAndToNextPart() {
  if (cur_num_question_ < count_questions_) {
    if (!CheckAnswer()) {
      GenerateNextPart();
    }
  } else {
    // result
  }
}

bool TranslationExercise::CheckAnswer() {
  if (translated_[cur_num_question_ - 1].toLower()
      != answer_->toPlainText().toLower()) {
    // IncIncorrect() -- 
    return IncIncorrect();;
  }
  return false;
}

void TranslationExercise::GenerateNextPart() {
  progress_bar_->setValue(cur_num_question_);
  sentence_label_->setText(sentences_[cur_num_question_++]);
  answer_->setText(tr(""));
}


