#include "BankController.h"

int BankController::findAccountByID(string id)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getID() == id)
        {
            return i;
        }
    }

    return -1;
}

string BankController::createAccount(
    string holderName,
    string pin,
    double initialBalance)
{
    Account account(
        holderName,
        pin,
        initialBalance);

    accounts.push_back(account);

    return account.getID();
}

bool BankController::deposit(
    string accountID,
    string pin,
    double amount)
{
    int index =
        findAccountByID(accountID);

    if (index == -1)
    {
        return false;
    }

    if (!accounts[index].verifyPIN(pin))
    {
        return false;
    }

    return accounts[index].deposit(amount);
}

bool BankController::withdraw(
    string accountID,
    string pin,
    double amount)
{
    int index =
        findAccountByID(accountID);

    if (index == -1)
    {
        return false;
    }

    if (!accounts[index].verifyPIN(pin))
    {
        return false;
    }

    return accounts[index].withdraw(amount);
}

bool BankController::transfer(
    string senderID,
    string senderPIN,
    string receiverID,
    double amount)
{
    int senderIndex =
        findAccountByID(senderID);

    int receiverIndex =
        findAccountByID(receiverID);

    if (senderIndex == -1 ||
        receiverIndex == -1)
    {
        return false;
    }

    if (!accounts[senderIndex]
             .verifyPIN(senderPIN))
    {
        return false;
    }

    bool success =
        accounts[senderIndex]
            .withdraw(amount);

    if (!success)
    {
        return false;
    }

    accounts[receiverIndex]
        .deposit(amount);

    return true;
}

Account* BankController::getAccount(
    string accountID,
    string pin)
{
    int index =
        findAccountByID(accountID);

    if (index == -1)
    {
        return nullptr;
    }

    if (!accounts[index]
             .verifyPIN(pin))
    {
        return nullptr;
    }

    return &accounts[index];
}

vector<Account>
BankController::getAllAccounts()
{
    return accounts;
}