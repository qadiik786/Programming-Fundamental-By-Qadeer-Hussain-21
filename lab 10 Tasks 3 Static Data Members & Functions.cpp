#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;

public:
    // Static data member declaration
    static int totalAccounts;

    BankAccount(string name, double initialBalance) 
        : accountHolderName(name), balance(initialBalance) {
        totalAccounts++;
    }

    void display() const {
        cout << "Account Holder: " << accountHolderName << " | Balance: $" << balance << endl;
    }
};

// Definition of static data member outside class
int BankAccount::totalAccounts = 0;

int main() {
    BankAccount acc1("Ali", 1000.0);
    BankAccount acc2("Junaid", 2500.0);
    BankAccount acc3("Hassan", 1500.0);

    acc1.display();
    acc2.display();
    acc3.display();

    cout << "\nTotal Bank Accounts Created: " << BankAccount::totalAccounts << endl;

    return 0;
}
