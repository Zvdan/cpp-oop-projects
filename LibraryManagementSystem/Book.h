#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
private:
    static int nextID;

    string id;
    string title;
    string author;
    bool borrowed;

public:
    Book(string title, string author);

    string getID() const;
    string getTitle() const;
    string getAuthor() const;

    bool isBorrowed() const;

    void borrowBook();
    void returnBook();
};

#endif