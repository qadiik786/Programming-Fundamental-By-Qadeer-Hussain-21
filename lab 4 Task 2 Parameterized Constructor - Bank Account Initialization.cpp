#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Parameterized Constructor
    BankAccount(string accNum, string accHolder, double bal) {
        accountNumber = accNum;
        accountHolder = accHolder;
        balance = bal;
    }

    // Function to show account details
    void showAccountDetails() {
        cout << "\n--- Bank Account Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    string accNum, accHolder;
    double bal;

    // Taking user input or assigning values
    cout << "Enter Account Number: ";
    cin >> accNum;
    cin.ignore(); // Clear input buffer
    cout << "Enter Account Holder Name: ";
    getline(cin, accHolder);
    cout << "Enter Initial Balance: ";
    cin >> bal;

    // Creating object using parameterized constructor
    BankAccount account(accNum, accHolder, bal);
    account.showAccountDetails();

    return 0;
}
