#ifndef EXERCISE_WIDGET_H_
#define EXERCISE_WIDGET_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QKeyEvent>
#include <QDialog>

#include <iostream>

class ExerciseWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExerciseWidget(QWidget* parent = nullptr);
  ~ExerciseWidget() override = default;

  void keyPressEvent(QKeyEvent* event) override;

  virtual void RestartFail();

 signals:
  void RestartSignal();

 protected:
  virtual void GenerateNewExercise() = 0;
  virtual void GenerateNextPart() = 0;
  virtual void CheckAnswer() = 0;
  virtual void CheckAnswerAndToNextPart() = 0;

  virtual void IncIncorrect();
  virtual void ShowTip();

  int count_questions_ = 5;
  int max_wrong_ = 2;
  int cur_num_question_ = 0;
  int count_incorrect_ = 0;

  QString cur_tip_;

  QVBoxLayout* layout_;

  QLabel* task_label_;
  QLabel* sentence_label_;

  QPushButton* submit_button_;

  QProgressBar* progress_bar_;  // red when incorrect

  // void ChangeToTranslation();
  // void ChangeToGrammar();
};

#endif  // EXERCISE_WIDGET_H_
