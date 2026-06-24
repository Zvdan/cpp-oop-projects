#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
private:
    static int nextID;

    string id;
    string holderName;
    string pin;
    double balance;

public:
    Account(string holderName,
        string pin,
        double initialBalance);

    string getID() const;

    string getHolderName() const;

    double getBalance() const;

    bool verifyPIN(string enteredPIN) const;

    bool deposit(double amount);

    bool withdraw(double amount);
};

#endif