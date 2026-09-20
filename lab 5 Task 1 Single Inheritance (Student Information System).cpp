#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    void getPersonInput() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void display_person_info() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class
class Student : public Person {
private:
    int student_id;

public:
    void getStudentInput() {
        getPersonInput();
        cout << "Enter Student ID: ";
        cin >> student_id;
    }

    void display_student_info() {
        display_person_info();
        cout << "Student ID: " << student_id << endl;
    }
};

int main() {
    Student s;
    cout << "--- Enter Student Details ---" << endl;
    s.getStudentInput();

    cout << "\n--- Displaying Student Information ---" << endl;
    s.display_student_info();

    return 0;
}
