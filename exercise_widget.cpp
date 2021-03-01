#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) {
  setParent(parent);
}

// ExerciseWidget::ExerciseWidget(QWidget* parent) : exercise_(nullptr) {
//   setParent(parent);
//   ChangeToTranslation();
// }
//
// void ExerciseWidget::ChangeToTranslation() {
//   // delete ?
//   // открепить родителя
//   delete exercise_;
//   exercise_ = new TranslationWidget(this);
// }
