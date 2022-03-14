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
  void GGLoadSentences();

  void GenerateNewExercise() final;
  void GenerateNextPart() final;
  bool CheckAnswer() final;

  std::vector<GrammarQuestion> exercises_;

  QGroupBox* radio_box_;

  // TODO: create different count if variants
  QRadioButton* variant_1_;
  QRadioButton* variant_2_;
  QRadioButton* variant_3_;
};

#endif  // GRAMMAR_EXERCISE_H_
