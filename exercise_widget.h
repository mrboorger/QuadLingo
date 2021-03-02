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
  ~ExerciseWidget() override = default;

 protected:
  virtual void GenerateNextPart() = 0;
  virtual void CheckAnswer() = 0;
  virtual void CheckAnswerAndToNextPart() = 0;

  // void ChangeToTranslation();
  // void ChangeToGrammar();
};

#endif  // EXERCISE_WIDGET_H_
