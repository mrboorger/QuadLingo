#include "tasks_loader.h"

std::vector<std::pair<QString, QString>>
TasksLoader::LoadTranslation(int cnt, int level) {
  std::ifstream in_eng;
  std::ifstream in_ans;
  switch (level) {
    case 0: {
      in_eng.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\translation\\easy\\tasks.txt");
      in_ans.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\translation\\easy\\answers.txt");
      break;
    }
    case 1: {
      in_eng.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\translation\\medium\\tasks.txt");
      in_ans.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\translation\\medium\\answers.txt");
      break;
    }
    case 2: {
      in_eng.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\translation\\hard\\tasks.txt");
      in_ans.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\translation\\hard\\answers.txt");
      break;
    }
    default: {
      break;
    }
  }

  std::vector<std::pair<QString, QString>> exercises;
  for (int i = 0; i < 10; ++i) {
    exercises.emplace_back();
    std::string str;
    std::getline(in_eng, str);
    exercises.back().first = QString::fromStdString(str);
    std::getline(in_ans, str);
    exercises.back().second = QString::fromStdString(str);
  }
  std::random_shuffle(exercises.begin(), exercises.end());
  exercises.resize(cnt);
  exercises.shrink_to_fit();
  return exercises;
}

QVector<GrammarQuestion> TasksLoader::LoadGrammar(int cnt) {
  Q_UNUSED(cnt);
  return QVector<GrammarQuestion>();
}
