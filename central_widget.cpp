#include "central_widget.h"

CentralWidget::CentralWidget(QWidget* parent) : layout_(new QHBoxLayout(this)),
    choice_widget_(new ChoiceWidget(this)),
    exercise_widget_(new EmptyExercise(this)) {
  setParent(parent);

  choice_widget_->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);
  layout_->addWidget(choice_widget_, 1);
  layout_->addWidget(exercise_widget_, 1);
  setLayout(layout_);

  connect(choice_widget_, &ChoiceWidget::ChangeToTranslationSignal,
          this, &CentralWidget::ChangeToTranslation);
}

void CentralWidget::ChangeToTranslation() {
  layout_->removeWidget(exercise_widget_);
  delete exercise_widget_;
  exercise_widget_ = new TranslationExercise(this);
  layout_->addWidget(exercise_widget_);
}

