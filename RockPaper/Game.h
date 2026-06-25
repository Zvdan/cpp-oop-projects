#pragma once
#include "Player.h"

class Game {
private:
    Player human;
    Player computer;

public:
    void getPlayerChoice();
    void generateComputerChoice();
    void displayChoices();
    void determineWinner();
    void play();
};