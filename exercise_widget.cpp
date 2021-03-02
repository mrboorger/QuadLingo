#include "exercise_widget.h"

ExerciseWidget::ExerciseWidget(QWidget* parent) :
    QWidget(parent),
    layout_(new QVBoxLayout()),
    task_label_(new QLabel()),
    sentence_label_(new QLabel()),
    submit_button_(new QPushButton("Submit")),
    progress_bar_(new QProgressBar)
    {
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

