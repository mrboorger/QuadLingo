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

  int count_questions_ = 5;
  int cur_num_question_ = 0;
  int count_incorrect_ = 0;

  QVector<QString> sentences_;
  QVector<QString> translated_;

  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;
  QTextEdit* answer_;
  QPushButton* submit_button_;

  QProgressBar* progress_bar_;  // red when incorrect
};

#endif  // TRANSLATION_EXERCISE_H_
