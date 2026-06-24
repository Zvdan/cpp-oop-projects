#ifndef BANKUI_H
#define BANKUI_H

#include "BankController.h"

class BankUI
{
private:
    BankController controller;

public:
    void displayMenu();

    void createAccountUI();

    void depositUI();

    void withdrawUI();

    void transferUI();

    void displayAccountUI();

    void run();
};

#endif