#include "Customer.h"

int Customer::nextID = 2000;

Customer::Customer(string name)
{
    id = to_string(nextID++);
    this->name = name;
}

string Customer::getID() const
{
    return id;
}

string Customer::getName() const
{
    return name;
}

vector<string> Customer::getBorrowedBookIDs() const
{
    return borrowedBookIDs;
}

void Customer::addBorrowedBook(string bookID)
{
    borrowedBookIDs.push_back(bookID);
}

bool Customer::removeBorrowedBook(string bookID)
{
    for (int i = 0; i < borrowedBookIDs.size(); i++)
    {
        if (borrowedBookIDs[i] == bookID)
        {
            borrowedBookIDs.erase(
                borrowedBookIDs.begin() + i);

            return true;
        }
    }

    return false;
}