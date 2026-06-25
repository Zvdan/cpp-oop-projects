#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"

using namespace std;

void Game::getPlayerChoice() {

    int choice;

    cout << "Choose:\n";
    cout << "0. Rock\n";
    cout << "1. Paper\n";
    cout << "2. Scissors\n";
    cout << "Enter your choice: ";

    cin >> choice;

    human.setChoice(choice);
}

void Game::generateComputerChoice() {
    computer.setChoice(rand() % 3);
}

void Game::displayChoices() {
    //                      0        1         2
    string choices[3] = { "Rock", "Paper", "Scissors" };

    cout << "\nYou chose: "
        << choices[human.getChoice()] << endl;

    cout << "Computer chose: "
        << choices[computer.getChoice()] << endl;
}

void Game::determineWinner() {
    int p = human.getChoice();
    int c = computer.getChoice();

    if (p == c) {
        cout << "Draw!\n";
    }
    else if ((p == 0 && c == 2) ||
        (p == 1 && c == 0) ||
        (p == 2 && c == 1)) {
        cout << "You Win!\n";
    }
    else {
        cout << "Computer Wins!\n";
    }
}

void Game::play() {
    getPlayerChoice();
    generateComputerChoice();
    displayChoices();
    determineWinner();
}