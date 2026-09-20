#include <iostream>
#include <string>
using namespace std;

class Voter {
    string name;
    int age;

public:
    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    // Function declaration
    bool isEligible();
    string getName() { return name; }
};

// Function definition OUTSIDE class
bool Voter::isEligible() {
    return age >= 18;
}

int main() {
    Voter v;
    string name;
    int age;

    cout << "Enter Voter Name: ";
    cin >> name;
    cout << "Enter Voter Age: ";
    cin >> age;

    v.setDetails(name, age);

    // Conditional output based on return value of isEligible()
    if (v.isEligible()) {
        cout << "\nResult: " << v.getName() << " is eligible to vote." << endl;
    } else {
        cout << "\nResult: " << v.getName() << " is NOT eligible to vote." << endl;
    }

    return 0;
}
