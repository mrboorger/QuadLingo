#ifndef CENTRAL_WIDGET_H_
#define CENTRAL_WIDGET_H_

#include <QWidget>
#include <QHBoxLayout>

#include "choice_widget.h"
#include "translation_widget.h"

class CentralWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CentralWidget(QWidget* parent = nullptr);

  void ChangeToTranslation();
 private:
  QHBoxLayout layout_;

  ChoiceWidget* choice_widget_;
  ExerciseWidget* exercise_widget_;
};

#endif  // CENTRAL_WIDGET_H_
