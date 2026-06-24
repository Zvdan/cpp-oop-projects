#ifndef LIBRARYUI_H
#define LIBRARYUI_H

#include "LibraryController.h"

class LibraryUI
{
private:
    LibraryController controller;

public:
    void displayMenu();

    void addBookUI();

    void addCustomerUI();

    void viewAvailableBooksUI();

    void borrowBookUI();

    void returnBookUI();

    void viewBorrowedBooksUI();

    void run();
};

#endif