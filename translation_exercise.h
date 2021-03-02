#ifndef TRANSLATION_EXERCISE_H_
#define TRANSLATION_EXERCISE_H_

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>

#include "exercise_widget.h"

class TranslationExercise : public ExerciseWidget {
  Q_OBJECT
 public:
  explicit TranslationExercise(QWidget* parent);

 private:
  void GenerateNextPart() final;
  void CheckAnswer() final;
  void CheckAnswerAndToNextPart() final; // move to public ? наследование приват

  void GGLoadSentences();  // to delete

  QVector<QString> sentences_;
  QVector<QString> translated_;

  QTextEdit* answer_;
};

#endif  // TRANSLATION_EXERCISE_H_
