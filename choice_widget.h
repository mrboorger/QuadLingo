#ifndef CHOICE_WIDGET_H_
#define CHOICE_WIDGET_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>
#include <QSpacerItem>

class ChoiceWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ChoiceWidget(QWidget* parent = nullptr);
  // void resizeEvent(QResizeEvent *event) override;

 private:
  QVBoxLayout* vert_layout_;
  QLabel* hello_label_;
  QLabel* start_label_;
  QPushButton* translation_button_;
  QPushButton* grammar_button_;
  QFont font_;
};

#endif  // CHOICE_WIDGET_H_
