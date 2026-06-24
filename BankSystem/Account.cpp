#include "Account.h"

int Account::nextID = 5000;

Account::Account(string holderName,
    string pin,
    double initialBalance)
{
    id = to_string(nextID++);

    this->holderName = holderName;
    this->pin = pin;

    if (initialBalance < 0)
    {
        balance = 0;
    }
    else
    {
        balance = initialBalance;
    }
}

string Account::getID() const
{
    return id;
}

string Account::getHolderName() const
{
    return holderName;
}

double Account::getBalance() const
{
    return balance;
}

bool Account::verifyPIN(string enteredPIN) const
{
    return pin == enteredPIN;
}

bool Account::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;

    return true;
}

bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (amount > balance)
    {
        return false;
    }

    balance -= amount;

    return true;
}