#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;

class Customer
{
private:
    static int nextID;

    string id;
    string name;

    vector<string> borrowedBookIDs;

public:
    Customer(string name);

    string getID() const;
    string getName() const;

    vector<string> getBorrowedBookIDs() const;

    void addBorrowedBook(string bookID);

    bool removeBorrowedBook(string bookID);
};

#endif