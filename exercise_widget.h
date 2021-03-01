#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class ExerciseWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);
  virtual ~ExerciseWidget() = default;

  // void ChangeToTranslation();
  // void ChangeToGrammar();

  virtual void GenerateNewSentence() = 0;
};

#endif  // EXERCISE_WIDGET_H_
