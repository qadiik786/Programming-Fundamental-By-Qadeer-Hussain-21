#include <iostream>
#include <string>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    float marks;

    void displayStudentInfo() {
        cout << "Full Name: " << firstName << " " << lastName << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    // Pointer to structure dynamically allocated on heap
    Student* studentPtr = new Student;

    // Assigning values dynamically using pointer arrow (->) operator
    cout << "Enter First Name: ";
    cin >> studentPtr->firstName;
    cout << "Enter Last Name: ";
    cin >> studentPtr->lastName;
    cout << "Enter Roll Number: ";
    cin >> studentPtr->rollNumber;
    cout << "Enter Marks: ";
    cin >> studentPtr->marks;

    // Calling member function using pointer
    cout << "\n--- Student Information (via Pointer) ---" << endl;
    studentPtr->displayStudentInfo();

    // Freeing allocated dynamic memory
    delete studentPtr;
    studentPtr = nullptr;

    return 0;
}
