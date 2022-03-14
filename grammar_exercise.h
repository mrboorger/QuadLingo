#ifndef GRAMMAR_EXERCISE_H_
#define GRAMMAR_EXERCISE_H_

#include <QGroupBox>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "exercise_widget.h"
#include "grammar_question.h"
#include "tasks_loader.h"

class GrammarExercise : public ExerciseWidget {
  Q_OBJECT
 public:
  explicit GrammarExercise(QWidget* parent, int level = 0);

 private:
  static constexpr int kMaxVariants = 6;

  void GenerateNewExercise() final;
  void GenerateNextPart() final;
  bool CheckAnswer() final;

  std::vector<GrammarQuestion> exercises_;

  QGroupBox* radio_box_;

  QVector<QRadioButton*> variants_;
};

#endif  // GRAMMAR_EXERCISE_H_
