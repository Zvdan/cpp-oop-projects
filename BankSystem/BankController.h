#ifndef BANKCONTROLLER_H
#define BANKCONTROLLER_H

#include <vector>
#include <string>

#include "Account.h"

using namespace std;

class BankController
{
private:
    vector<Account> accounts;

    int findAccountByID(string id);

public:
    string createAccount(string holderName,
        string pin,
        double initialBalance);

    bool deposit(string accountID,
        string pin,
        double amount);

    bool withdraw(string accountID,
        string pin,
        double amount);

    bool transfer(string senderID,
        string senderPIN,
        string receiverID,
        double amount);

    Account* getAccount(string accountID,
        string pin);

    vector<Account> getAllAccounts();
};

#endif