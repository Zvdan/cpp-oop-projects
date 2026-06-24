#include <iostream>
#include <string>

#include "BankUI.h"

using namespace std;

void BankUI::displayMenu()
{
    cout << "\n===== Bank Management System =====\n";

    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Transfer Money\n";
    cout << "5. Display Account Information\n";
    cout << "6. Exit\n";
}

void BankUI::createAccountUI()
{
    string name;
    string pin;
    double initialBalance;

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Create PIN: ";
    getline(cin, pin);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    cin.ignore();

    string id =
        controller.createAccount(
            name,
            pin,
            initialBalance);

    cout << "\nAccount Created Successfully.\n";

    cout << "Generated Account ID: "
        << id << endl;
}

void BankUI::depositUI()
{
    string id;
    string pin;
    double amount;

    cout << "Enter Account ID: ";
    getline(cin, id);

    cout << "Enter PIN: ";
    getline(cin, pin);

    cout << "Enter Amount: ";
    cin >> amount;
    cin.ignore();

    if (controller.deposit(
        id,
        pin,
        amount))
    {
        Account* account =
            controller.getAccount(
                id,
                pin);

        cout << "Deposit Successful.\n";

        cout << "Current Balance: "
            << account->getBalance()
            << endl;
    }
    else
    {
        cout << "Deposit Failed.\n";
    }
}

void BankUI::withdrawUI()
{
    string id;
    string pin;
    double amount;

    cout << "Enter Account ID: ";
    getline(cin, id);

    cout << "Enter PIN: ";
    getline(cin, pin);

    cout << "Enter Amount: ";
    cin >> amount;
    cin.ignore();

    if (controller.withdraw(
        id,
        pin,
        amount))
    {
        Account* account =
            controller.getAccount(
                id,
                pin);

        cout << "Withdrawal Successful.\n";

        cout << "Remaining Balance: "
            << account->getBalance()
            << endl;
    }
    else
    {
        cout << "Withdrawal Failed.\n";
    }
}

void BankUI::transferUI()
{
    string senderID;
    string senderPIN;
    string receiverID;

    double amount;

    cout << "Enter Sender Account ID: ";
    getline(cin, senderID);

    cout << "Enter Sender PIN: ";
    getline(cin, senderPIN);

    cout << "Enter Receiver Account ID: ";
    getline(cin, receiverID);

    cout << "Enter Amount: ";
    cin >> amount;
    cin.ignore();

    if (controller.transfer(
        senderID,
        senderPIN,
        receiverID,
        amount))
    {
        cout << "Transfer Successful.\n";
    }
    else
    {
        cout << "Transfer Failed.\n";
    }
}

void BankUI::displayAccountUI()
{
    string id;
    string pin;

    cout << "Enter Account ID: ";
    getline(cin, id);

    cout << "Enter PIN: ";
    getline(cin, pin);

    Account* account =
        controller.getAccount(
            id,
            pin);

    if (account == nullptr)
    {
        cout << "Account Not Found.\n";
        return;
    }

    cout << "\n===== Account Information =====\n";

    cout << "Account ID: "
        << account->getID()
        << endl;

    cout << "Holder Name: "
        << account->getHolderName()
        << endl;

    cout << "Balance: "
        << account->getBalance()
        << endl;
}

void BankUI::run()
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
            createAccountUI();
            break;

        case 2:
            depositUI();
            break;

        case 3:
            withdrawUI();
            break;

        case 4:
            transferUI();
            break;

        case 5:
            displayAccountUI();
            break;

        case 6:
            cout << "Goodbye.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);
}