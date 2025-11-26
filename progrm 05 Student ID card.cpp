#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name,rollNumber,department,session;

    void displayID() const {
        cout << "---------------------" << '\n';
        cout << "   STUDENT ID CARD   " << '\n';
        cout << "---------------------" << '\n';
        cout << "Name: " << name << '\n';
        cout << "Roll Number: " << rollNumber << '\n';
        cout << "Department: " << department << '\n';
        cout << "Session: " << session << '\n';
    }
};

int main() {
    Student s;

    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Roll Number: ";
    getline(cin, s.rollNumber);
    cout << "Enter Department: ";
    getline(cin, s.department);
    cout << "Enter Session: ";
    getline(cin, s.session);

    s.displayID();
    return 0;
}
