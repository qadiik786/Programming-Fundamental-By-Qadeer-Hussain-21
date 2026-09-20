#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    void display_person() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class 1
class Employee : public Person {
protected:
    int employee_id;

public:
    void display_employee() {
        display_person();
        cout << "Employee ID: " << employee_id << endl;
    }
};

// Derived Class 2 (Multilevel)
class Manager : public Employee {
private:
    string department;

public:
    void getInput() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Employee ID: ";
        cin >> employee_id;
        cin.ignore(); // Clear newline buffer
        cout << "Enter Department: ";
        getline(cin, department);
    }

    void display_manager() {
        display_employee();
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager m;
    cout << "--- Enter Manager Details ---" << endl;
    m.getInput();

    cout << "\n--- Displaying Manager Information ---" << endl;
    m.display_manager();

    return 0;
}
