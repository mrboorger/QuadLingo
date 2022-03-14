#ifndef TRANSLATION_EXERCISE_H_
#define TRANSLATION_EXERCISE_H_

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "exercise_widget.h"
#include "tasks_loader.h"

class TranslationExercise : public ExerciseWidget {
  Q_OBJECT
 public:
  explicit TranslationExercise(QWidget* parent, int level = 0);

 private:
  void GenerateNewExercise() final;
  void GenerateNextPart() final;
  bool CheckAnswer() final;

  std::vector<std::pair<QString, QString>> exercises_;

  QTextEdit* answer_;
};

#endif  // TRANSLATION_EXERCISE_H_
