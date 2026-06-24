#include "LibraryController.h"

int LibraryController::findBookByID(
    string bookID)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getID() == bookID)
        {
            return i;
        }
    }

    return -1;
}

int LibraryController::findCustomerByID(
    string customerID)
{
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getID() ==
            customerID)
        {
            return i;
        }
    }

    return -1;
}

string LibraryController::addBook(
    string title,
    string author)
{
    Book book(title, author);

    books.push_back(book);

    return book.getID();
}

vector<Book> LibraryController::getAvailableBooks()
{
    vector<Book> availableBooks;

    for (int i = 0; i < books.size(); i++)
    {
        if (!books[i].isBorrowed())
        {
            availableBooks.push_back(
                books[i]);
        }
    }

    return availableBooks;
}

vector<Book> LibraryController::getAllBooks()
{
    return books;
}

string LibraryController::addCustomer(
    string name)
{
    Customer customer(name);

    customers.push_back(customer);

    return customer.getID();
}

vector<Customer>
LibraryController::getAllCustomers()
{
    return customers;
}

bool LibraryController::borrowBook(
    string customerID,
    string bookID)
{
    int customerIndex =
        findCustomerByID(customerID);

    int bookIndex =
        findBookByID(bookID);

    if (customerIndex == -1 ||
        bookIndex == -1)
    {
        return false;
    }

    if (books[bookIndex].isBorrowed())
    {
        return false;
    }

    books[bookIndex].borrowBook();

    customers[customerIndex]
        .addBorrowedBook(bookID);

    return true;
}

bool LibraryController::returnBook(
    string customerID,
    string bookID)
{
    int customerIndex =
        findCustomerByID(customerID);

    int bookIndex =
        findBookByID(bookID);

    if (customerIndex == -1 ||
        bookIndex == -1)
    {
        return false;
    }

    bool removed =
        customers[customerIndex]
        .removeBorrowedBook(bookID);

    if (!removed)
    {
        return false;
    }

    books[bookIndex].returnBook();

    return true;
}

vector<Book>
LibraryController::getBorrowedBooks(
    string customerID)
{
    vector<Book> borrowedBooks;

    int customerIndex =
        findCustomerByID(customerID);

    if (customerIndex == -1)
    {
        return borrowedBooks;
    }

    vector<string> bookIDs =
        customers[customerIndex]
        .getBorrowedBookIDs();

    for (int i = 0; i < bookIDs.size(); i++)
    {
        int bookIndex =
            findBookByID(bookIDs[i]);

        if (bookIndex != -1)
        {
            borrowedBooks.push_back(
                books[bookIndex]);
        }
    }

    return borrowedBooks;
}