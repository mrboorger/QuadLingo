#ifndef TASKS_LOADER_H_
#define TASKS_LOADER_H_

#include <QFile>
#include <QSet>
#include <QString>
#include <QVector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "grammar_question.h"

class TasksLoader {
 public:
  static std::vector<std::pair<QString, QString>> LoadTranslation(int cnt, int level);
  static std::vector<GrammarQuestion> LoadGrammar(int cnt, int level);

 private:
  static const inline QSet<QString> kNeededTranslation = {"text", "translated"};
  static const inline QSet<QString> kNeededGrammar = {"question", "variants", "answer", "tip"};

  static QJsonObject LoadJson(QString file_path);
  static bool IfJsonContainsFields(QJsonObject exercise_obj, QSet<QString> needed);
  static std::pair<QString, QString> GetTranslationFromJson(QJsonObject exercise_obj);
  static GrammarQuestion GetGrammarFromJson(QJsonObject exercise_obj);
};

#endif  // TASKS_LOADER_H_
