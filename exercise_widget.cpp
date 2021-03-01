#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) : exercise_(nullptr) {
  setParent(parent);
  ChangeToTranslation();
  // ChangeToGrammar();
}

void ExerciseWidget::ChangeToTranslation() {
  // delete ?
  // открепить родителя ?
  delete exercise_;
  // наследование можно(нужно?) убрать
  exercise_ = new TranslationWidget(this);
}

void ExerciseWidget::ChangeToGrammar() {
  // delete ?
  // открепить родителя ?
  delete exercise_;
  // наследование можно(нужно?) убрать
  exercise_ = new GrammarWidget(this);
}

void ExerciseWidget::GenerateNewSentence() {

}
