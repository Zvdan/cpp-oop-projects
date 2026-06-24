#include "Quiz.h"
#include <iostream>
using namespace std;

void Quiz::addQuestion() {
    Question q;
    string text, answer;
    int numAnswers, correct;

    cout << "Enter question: ";
    cin.ignore();
    getline(cin, text);
    q.setQuestion(text);

    cout << "How many answers? ";
    cin >> numAnswers;

    cin.ignore();

    for (int i = 0; i < numAnswers; i++) {
        cout << "Answer " << i + 1 << ": ";
        getline(cin, answer);
        q.addAnswer(answer);
    }

    cout << "Enter correct answer number (1-" << numAnswers << "): ";
    cin >> correct;

    q.setCorrectIndex(correct - 1);

    questions.push_back(q);

    cout << "Question added successfully!\n";
}

void Quiz::takeQuiz() {
    if (questions.empty()) {
        cout << "No questions available!\n";
        return;
    }

    int score = 0;
    int userAnswer;

    for (int i = 0; i < questions.size(); i++) {
        Question q = questions[i];

        cout << "\nQ" << i + 1 << ": " << q.getQuestion() << "\n";

        vector<string> ans = q.getAnswers();
        for (int j = 0; j < ans.size(); j++) {
            cout << j + 1 << ") " << ans[j] << "\n";
        }

        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer - 1 == q.getCorrectIndex()) {
            score++;
        }
    }

    cout << "\nFinal Score: " << score << "/" << questions.size() << "\n";
}