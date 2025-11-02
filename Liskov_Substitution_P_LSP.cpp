#include <iostream>
#include <vector>
#include <string>
using namespace std;
class DepositOnlyAccount
{
public:
    virtual void deposit(const double &amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount
{
public:
    virtual void withdrawl(const double &amount) = 0;
};
class SavingAct : public WithdrawableAccount
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
class CurrentAct : public WithdrawableAccount
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
class FIxedDepositAct : public DepositOnlyAccount
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
    vector<DepositOnlyAccount *> vd;
    vector<WithdrawableAccount *> vw;

public:
    Client(vector<WithdrawableAccount *> &vecw, vector<DepositOnlyAccount *> vecd)
    {
        cout << "Ctor of client " << endl;
        vd = vecd;
        vw = vecw;
    }
    void processTheTransaction()
    {
        cout << "process the amount " << endl;
        for (auto i : vw)
        {
            i->deposit(1000);
            i->withdrawl(500);
        }
        for (auto i : vd)
        {
            i->deposit(1000);
        }
    }
};

int main()
{
    vector<WithdrawableAccount *> vw;
    vw.push_back(new SavingAct());
    vw.push_back(new CurrentAct());
    vector<DepositOnlyAccount *> vd;
    vd.push_back(new FIxedDepositAct());
    Client clnt(vw, vd);
    clnt.processTheTransaction();
    return 0;
};
