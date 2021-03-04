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
  void GenerateNewExercise() final;
  void GenerateNextPart() final;
  bool CheckAnswer() final;

  void GGLoadSentences();  // to delete

  QVector<QString> sentences_;
  QVector<QString> translated_;

  QTextEdit* answer_;
};

#endif  // TRANSLATION_EXERCISE_H_
