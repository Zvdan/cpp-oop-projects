#include <iostream>
#include <string>
#include <vector>

#include "LibraryUI.h"

using namespace std;

void LibraryUI::displayMenu()
{
    cout << "\n===== Library Management System =====\n";

    cout << "1. View Available Books\n";
    cout << "2. Borrow Book\n";
    cout << "3. Return Book\n";
    cout << "4. View My Borrowed Books\n";
    cout << "5. Add Book\n";
    cout << "6. Add Customer\n";
    cout << "7. Exit\n";
}

void LibraryUI::addBookUI()
{
    string title;
    string author;

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    string id =
        controller.addBook(title, author);

    cout << "Book Added Successfully.\n";
    cout << "Generated Book ID: "
        << id << endl;
}

void LibraryUI::addCustomerUI()
{
    string name;

    cout << "Enter Customer Name: ";
    getline(cin, name);

    string id =
        controller.addCustomer(name);

    cout << "Customer Added Successfully.\n";
    cout << "Generated Customer ID: "
        << id << endl;
}

void LibraryUI::viewAvailableBooksUI()
{
    vector<Book> books =
        controller.getAvailableBooks();

    if (books.empty())
    {
        cout << "No Available Books.\n";
        return;
    }

    cout << "\nAvailable Books:\n";

    for (int i = 0; i < books.size(); i++)
    {
        cout << "\nBook ID: "
            << books[i].getID()
            << endl;

        cout << "Title: "
            << books[i].getTitle()
            << endl;

        cout << "Author: "
            << books[i].getAuthor()
            << endl;
    }
}

void LibraryUI::borrowBookUI()
{
    string customerID;
    string bookID;

    cout << "Enter Customer ID: ";
    getline(cin, customerID);

    cout << "Enter Book ID: ";
    getline(cin, bookID);

    if (controller.borrowBook(
        customerID,
        bookID))
    {
        cout << "Book Borrowed Successfully.\n";
    }
    else
    {
        cout << "Borrow Operation Failed.\n";
    }
}

void LibraryUI::returnBookUI()
{
    string customerID;

    cout << "Enter Customer ID: ";
    getline(cin, customerID);

    vector<Book> borrowedBooks =
        controller.getBorrowedBooks(
            customerID);

    if (borrowedBooks.empty())
    {
        cout << "No Borrowed Books Found.\n";
        return;
    }

    cout << "\nBorrowed Books:\n";

    for (int i = 0;
        i < borrowedBooks.size();
        i++)
    {
        cout << i + 1
            << ". "
            << borrowedBooks[i]
            .getTitle()
            << endl;
    }

    int choice;

    cout << "Choose Book Number: ";
    cin >> choice;
    cin.ignore();

    if (choice < 1 ||
        choice > borrowedBooks.size())
    {
        cout << "Invalid Choice.\n";
        return;
    }

    string bookID =
        borrowedBooks[choice - 1]
        .getID();

    if (controller.returnBook(
        customerID,
        bookID))
    {
        cout << "Book Returned Successfully.\n";
    }
    else
    {
        cout << "Return Failed.\n";
    }
}

void LibraryUI::viewBorrowedBooksUI()
{
    string customerID;

    cout << "Enter Customer ID: ";
    getline(cin, customerID);

    vector<Book> borrowedBooks =
        controller.getBorrowedBooks(
            customerID);

    if (borrowedBooks.empty())
    {
        cout << "No Borrowed Books Found.\n";
        return;
    }

    cout << "\nBorrowed Books:\n";

    for (int i = 0;
        i < borrowedBooks.size();
        i++)
    {
        cout << "\nBook ID: "
            << borrowedBooks[i].getID()
            << endl;

        cout << "Title: "
            << borrowedBooks[i]
            .getTitle()
            << endl;

        cout << "Author: "
            << borrowedBooks[i]
            .getAuthor()
            << endl;
    }
}

void LibraryUI::run()
{
    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter Choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            viewAvailableBooksUI();
            break;

        case 2:
            borrowBookUI();
            break;

        case 3:
            returnBookUI();
            break;

        case 4:
            viewBorrowedBooksUI();
            break;

        case 5:
            addBookUI();
            break;

        case 6:
            addCustomerUI();
            break;

        case 7:
            cout << "Goodbye.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 7);
}