#include "translation_exercise.h"

TranslationExercise::TranslationExercise(QWidget* parent) : ExerciseWidget(
    parent) {
  task_label_ = new QLabel("Translate this sentence", this);
  sentence_label_ = new QLabel("Make America Great again", this);
  answer_ = new QTextEdit(this);
  answer_->setPlaceholderText(tr("Write a translation here"));
  submit_button_ = new QPushButton("Submit", this);
  layout_ = new QVBoxLayout(this);

  layout_->addWidget(task_label_);

  layout_->addWidget(sentence_label_);

  layout_->addWidget(answer_);

  layout_->addWidget(submit_button_);

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
  CheckTranslation();

  if (cur_num_question_ < count_questions_) {
    GenerateNextPart();
  } else {
    // result
  }
}

void TranslationExercise::CheckTranslation() {
  if (translated_[cur_num_question_ - 1].toLower()
      != answer_->toPlainText().toLower()) {
    ++count_incorrect_;
  }
  answer_->setText(tr(""));
}

void TranslationExercise::GenerateNextPart() {
  sentence_label_->setText(sentences_[cur_num_question_++]);
}
