#include <iostream>
#include <string>
using namespace std;

// Student Structure Definition
struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    float marks;

    // Member function to display details
    void displayStudentInfo() {
        cout << "Full Name: " << firstName << " " << lastName << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    // Structure variable creation
    Student student1;

    // Assigning values to members
    student1.firstName = "Ali";
    student1.lastName = "Khan";
    student1.rollNumber = 101;
    student1.marks = 88.5;

    // Calling member function
    cout << "--- Student Information ---" << endl;
    student1.displayStudentInfo();

    return 0;
}
