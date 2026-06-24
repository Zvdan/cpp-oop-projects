#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> answers;
    int correctIndex;

public:
    Question();

    void setQuestion(const string& q);
    void addAnswer(const string& answer);
    void setCorrectIndex(int index);

    string getQuestion() const;
    vector<string> getAnswers() const;
    int getCorrectIndex() const;
};

#endif