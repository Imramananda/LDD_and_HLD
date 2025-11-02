#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Account
{
public:
    virtual void deposit(const double &) = 0;
    virtual void withdrawl(const double &) = 0;
};

class SavingAct : public Account
{
public:
    double totalAmount = 0;
    SavingAct()
    {
        cout << "Saving Account " << endl;
    }
    void deposit(const double &amount)
    {
        cout << "Adding the amount in saving account : " << amount << endl;
        totalAmount = totalAmount + amount;
    }
    void withdrawl(const double &w)
    {
        if (totalAmount > w)
        {
            cout << "Amount can be withdrawl from saving " << w << endl;
            totalAmount = totalAmount = w;
        }
        cout << "After withodrawl amount is : " << totalAmount << endl;
    }
};
class CurrentAct : public Account
{
public:
    double totalAmount = 0;
    CurrentAct()
    {
        cout << "CurrentAccount " << endl;
    }
    void deposit(const double &amount)
    {
        cout << "Adding the amount in Current account : " << amount << endl;
        totalAmount = totalAmount + amount;
    }
    void withdrawl(const double &w)
    {
        if (totalAmount > w)
        {
            cout << "Amount can be withdrawl from Current  " << w << endl;
            totalAmount = totalAmount = w;
        }
        cout << "After withodrawl amount is : " << totalAmount << endl;
    }
};
class FIxedDepositAct : public Account
{
public:
    double totalAmount = 0;
    FIxedDepositAct()
    {
        cout << "FIxedDepositAct " << endl;
    }
    void deposit(const double &amount)
    {
        cout << "Adding the amount in FIxedDepositAct account : " << amount << endl;
        totalAmount = totalAmount + amount;
    }
    void withdrawl(const double &w)
    {

        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};
class Client
{
    vector<Account *> v;

public:
    Client(vector<Account *> &vec)
    {
        cout << "Ctor of client " << endl;
        v = vec;
    }
    void processTheTransaction()
    {
        cout << "process the amount " << endl;
        for (auto i : v)
        {
            i->deposit(1000);
            i->withdrawl(500);
        }
    }
};

int main()
{
    vector<Account *> v;
    v.push_back(new SavingAct());
    v.push_back(new CurrentAct());
    v.push_back(new FIxedDepositAct());
    Client clnt(v);
    clnt.processTheTransaction();
    return 0;
};
