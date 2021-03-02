#include "translation_exercise.h"

TranslationExercise::TranslationExercise(QWidget* parent) : ExerciseWidget(
    parent) {
  task_label_ = new QLabel("Translate this sentence", this);
  sentence_label_ = new QLabel(this);
  answer_ = new QTextEdit(this);
  answer_->setPlaceholderText(tr("Write a translation here"));
  submit_button_ = new QPushButton("Submit", this);
  layout_ = new QVBoxLayout(this);
  progress_bar_ = new QProgressBar(this);

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
  GGLoadSentences();
  GenerateNextPart();
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

void TranslationExercise::CheckAnswerAndToNextPart() {
  CheckAnswer();

  progress_bar_->setValue(cur_num_question_);
  if (cur_num_question_ < count_questions_) {
    GenerateNextPart();
  } else {
    // result
  }
}

void TranslationExercise::CheckAnswer() {
  if (translated_[cur_num_question_ - 1].toLower()
      != answer_->toPlainText().toLower()) {
    ++count_incorrect_;
  }
}

void TranslationExercise::GenerateNextPart() {
  sentence_label_->setText(sentences_[cur_num_question_++]);
  answer_->setText(tr(""));
}
