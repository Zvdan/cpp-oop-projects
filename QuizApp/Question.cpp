#include "Question.h"

Question::Question() {
    correctIndex = -1;
}

void Question::setQuestion(const string& q) {
    questionText = q;
}

void Question::addAnswer(const string& answer) {
    answers.push_back(answer);
}

void Question::setCorrectIndex(int index) {
    correctIndex = index;
}

string Question::getQuestion() const {
    return questionText;
}

vector<string> Question::getAnswers() const {
    return answers;
}

int Question::getCorrectIndex() const {
    return correctIndex;
}