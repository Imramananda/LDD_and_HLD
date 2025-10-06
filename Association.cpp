
#include<iostream>
using namespace std;

class Bank {
public:
    void transferMoney(Account* fromAccount, Account* toAccount, double amount) {
        // Code to transfer money from one account to another
        cout<<"Account balance : "<<fromAccount->getBalance()<<" id : "<<fromAccount->getId()<<endl;
        cout<<"Account balance : "<<toAccount->getBalance()<<" id : "<<toAccount->getId()<<endl;
    }
};

class Account {
public:
    Account(int id, double balance) : id(id), balance(balance) {}
    int getId() { return id; }
    double getBalance() { return balance; }
private:
    int id;
    double balance;
};



int main() {
    Account* account1 = new Account(123, 1000.00);
    Account* account2 = new Account(456, 500.00);
    Bank bank;
    bank.transferMoney(account1, account2, 250.00);
    return 0;
}