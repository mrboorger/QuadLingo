#include "grammar_exercise.h"

GrammarExercise::GrammarExercise(QWidget* parent, int level) : ExerciseWidget(parent, level) {
  radio_box_ = new QGroupBox(this);

  task_label_->setText("Choose the right answer:");

  sentence_label_->setWordWrap(true);
  submit_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  auto* radio_layout_ = new QVBoxLayout();

  for (int i = 0; i < kMaxVariants; ++i) {
    variants_.push_back(new QRadioButton());
    radio_layout_->addWidget(variants_.back());
  }

  radio_box_->setLayout(radio_layout_);

  layout_->addWidget(task_label_, 1);

  layout_->addWidget(sentence_label_, 2);

  layout_->addWidget(radio_box_, 3);

  layout_->addWidget(submit_button_, 1);

  layout_->addWidget(progress_bar_, 1);

  progress_bar_->setMaximum(count_questions_);

  setLayout(layout_);

  connect(submit_button_, &QPushButton::clicked, this, &GrammarExercise::CheckAnswerAndToNextPart);
  GenerateNewExercise();
}

void GrammarExercise::GenerateNewExercise() {
  exercises_.clear();
  count_incorrect_ = 0;
  cur_num_question_ = 0;

  exercise_timer_->setSingleShot(true);
  exercise_timer_->setInterval(time_to_solve_);
  exercise_timer_->start();

  // GGLoadSentences();
  exercises_ = TasksLoader::LoadGrammar(count_questions_, difficulty_level_);
  GenerateNextPart();

  repaint();
}

bool GrammarExercise::CheckAnswer() {
  const QRadioButton* selected_variant = nullptr;

  for (auto& variant : variants_) {
    if (variant->isChecked()) {
      selected_variant = variant;
    }
  }

  if (exercises_[cur_num_question_ - 1].answer != selected_variant->text()) {
    return IncIncorrect();
  }
  return false;
}

void GrammarExercise::GenerateNextPart() {
  progress_bar_->setValue(cur_num_question_);
  ++cur_num_question_;
  cur_tip_ = exercises_[cur_num_question_ - 1].tip;
  sentence_label_->setText(exercises_[cur_num_question_ - 1].question);

  for (int i = 0; i < kMaxVariants; ++i) {
    variants_[i]->hide();
  }
  for (int i = 0; i < exercises_[cur_num_question_ - 1].variants.size(); ++i) {
    variants_[i]->setText(exercises_[cur_num_question_ - 1].variants[i]);
    variants_[i]->show();
  }

  variants_[0]->setChecked(true);
}
