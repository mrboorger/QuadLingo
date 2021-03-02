#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) {
  setParent(parent);
  // ChangeToTranslation();
  // ChangeToGrammar();
}

// void ExerciseWidget::ChangeToTranslation() {
//   // delete ?
//   // открепить родителя ?
//   delete exercise_;
//   // наследование можно(нужно?) убрать
//   exercise_ = new TranslationExercise(this);
// }
//
// void ExerciseWidget::ChangeToGrammar() {
//   // delete ?
//   // открепить родителя ?
//   delete exercise_;
//   // наследование можно(нужно?) убрать
//   exercise_ = new GrammarExercise(this);
// }

