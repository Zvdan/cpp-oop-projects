#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"
#include <vector>
using namespace std;

class Quiz {
private:
    vector<Question> questions;

public:
    void addQuestion();
    void takeQuiz();
};

#endif