#ifndef LIBRARYCONTROLLER_H
#define LIBRARYCONTROLLER_H

#include <vector>
#include <string>

#include "Book.h"
#include "Customer.h"

using namespace std;

class LibraryController
{
private:
    vector<Book> books;
    vector<Customer> customers;

    int findBookByID(string bookID);
    int findCustomerByID(string customerID);

public:

   
    string addBook(string title, string author);

    vector<Book> getAvailableBooks();

    vector<Book> getAllBooks();


    string addCustomer(string name);

    vector<Customer> getAllCustomers();

    bool borrowBook(string customerID,
        string bookID);

    bool returnBook(string customerID,
        string bookID);

    vector<Book> getBorrowedBooks(
        string customerID);
};

#endif