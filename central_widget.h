#ifndef CENTRAL_WIDGET_H_
#define CENTRAL_WIDGET_H_

#include <QWidget>
#include <QHBoxLayout>

#include "exercise_widget.h"
#include "choice_widget.h"

class CentralWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CentralWidget(QWidget* parent = nullptr);

 private:
  QHBoxLayout layout_;

  ChoiceWidget* choice_widget_;
  ExerciseWidget* exercise_widget_;
};

#endif  // CENTRAL_WIDGET_H_
