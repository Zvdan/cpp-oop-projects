#include "Book.h"

int Book::nextID = 1000;

Book::Book(string title, string author)
{
    id = to_string(nextID++);
    this->title = title;
    this->author = author;

    borrowed = false;
}

string Book::getID() const
{
    return id;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

bool Book::isBorrowed() const
{
    return borrowed;
}

void Book::borrowBook()
{
    borrowed = true;
}

void Book::returnBook()
{
    borrowed = false;
}