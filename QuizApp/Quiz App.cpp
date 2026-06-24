#include <iostream>
#include "Quiz.h"
using namespace std;

int main() {
    Quiz quiz;
    int choice;

    do {
        cout << "\n===== Quiz App =====\n";
        cout << "1. Add Question\n";
        cout << "2. Take Quiz\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            quiz.addQuestion();
            break;

        case 2:
            quiz.takeQuiz();
            break;

        case 3:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}