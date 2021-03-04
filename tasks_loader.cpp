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

std::vector<GrammarQuestion> TasksLoader::LoadGrammar(int cnt, int level) {
  std::ifstream in_tsk;
  std::ifstream in_var;
  std::ifstream in_ans;
  std::ifstream in_tps;
  switch (level) {
    case 0: {
      in_tsk.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\easy\\tasks.txt");
      in_ans.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\easy\\answers.txt");
      in_var.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\easy\\variants.txt");
      in_tps.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\easy\\tips.txt");
      break;
    }
    case 1: {
      in_tsk.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\medium\\tasks.txt");
      in_ans.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\medium\\answers.txt");
      in_var.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\medium\\variants.txt");
      in_tps.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\medium\\tips.txt");
      break;
    }
    case 2: {
      in_tsk.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\hard\\tasks.txt");
      in_ans.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\hard\\answers.txt");
      in_var.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\hard\\variants.txt");
      in_tps.open(
          "c:\\Users\\mrboorger\\CLionProjects\\QuadLingo\\cmake-build-debug\\exercises\\grammar\\hard\\tips.txt");
      break;
    }
    default: {
      break;
    }
  }
  std::vector<GrammarQuestion> exercises;
  for (int i = 0; i < 10; ++i) {
    exercises.emplace_back();
    std::string str;
    std::getline(in_tsk, str);
    exercises.back().question = QString::fromStdString(str);
    std::getline(in_ans, str);
    exercises.back().answer = QString::fromStdString(str);
    std::getline(in_tps, str);
    exercises.back().tip = QString::fromStdString(str);
    for (int j = 0; j < 3; ++j) {
      in_var >> str;
      exercises.back().variants.push_back(QString::fromStdString(str));
    }
  }
  std::random_shuffle(exercises.begin(), exercises.end());
  exercises.resize(cnt);
  exercises.shrink_to_fit();
  return exercises;
}
