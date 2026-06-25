#pragma once
#include <string>

class Player {
private:
    int choice; // index

public:
    void setChoice(int c);
    int getChoice() const;
};