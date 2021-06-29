#include <iostream>

using namespace std;

class Bank_Account
{
private:
    string customer_name;
    unsigned int account_no;
    string type_of_account = "Not given";
    int balance_amount = 0;

public:
    void customerDetails(string name, unsigned int ac_no)
    {
        customer_name = name;
        account_no = ac_no;
    }
    void accountType(string type)
    {
        if (type == "Current" || type == "Saving")
            type_of_account = type;
        else
            cout << "Error : type name is invalid" << endl;
    }
    void balance()
    {
        cout << "Current balance :" << balance_amount << endl;
    }
    void deposit(int deposit)
    {
        balance_amount = balance_amount + deposit;
        cout << "final balance :" << balance_amount << endl;
    }
    void withdraw(int withdraw)
    {
        if (withdraw > balance_amount)
            cout << "Error : Withdraw money is more than current amount " << endl;
        else if (withdraw <= 0)
        {
            cout << "Please enter a valid amount" << endl;
        }
        else
            balance_amount = balance_amount - withdraw;
    }
    void display()
    {
        cout << endl;
        cout << "Customer Details ------------- " << endl;
        cout << "Customer name :" << customer_name << endl;
        cout << "Account number :" << account_no << endl;
        cout << "Type of account :" << type_of_account << endl;
        cout << "Balance amount in the account :" << balance_amount << endl;
    }
};

int main()
{
    Bank_Account account1, account2;
    account1.customerDetails("Avatar", 13);
    account1.accountType("Saving");
    account1.balance();
    account1.deposit(2000);
    account1.withdraw(500);
    account1.display();

    cout << "-------------------" << endl;
    account2.customerDetails("Monster", 22);
    account2.accountType("agarabagara");
    account2.balance();
    account2.deposit(3100);
    account2.withdraw(-500);
    account2.display();

    return 0;
}