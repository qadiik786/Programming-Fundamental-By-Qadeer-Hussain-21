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
    int count;
    cout << "Enter number of students: ";
    cin >> count;

    // Array of pointers to Student structure
    Student* studentPtrs[100];

    // Dynamically allocating memory for each student and taking input
    for (int i = 0; i < count; i++) {
        studentPtrs[i] = new Student; // Allocating dynamic memory for each object

        cout << "\nEnter details for Student " << i + 1 << ":" << endl;
        cout << "First Name: ";
        cin >> studentPtrs[i]->firstName;
        cout << "Last Name: ";
        cin >> studentPtrs[i]->lastName;
        cout << "Roll Number: ";
        cin >> studentPtrs[i]->rollNumber;
        cout << "Marks: ";
        cin >> studentPtrs[i]->marks;
    }

    // Displaying details using pointers
    cout << "\n===============================" << endl;
    cout << "--- STUDENT RECORDS (Via Pointers) ---" << endl;
    cout << "===============================" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        studentPtrs[i]->displayStudentInfo();
        cout << "-------------------------------" << endl;
    }

    // Deallocating dynamically allocated memory
    for (int i = 0; i < count; i++) {
        delete studentPtrs[i];
        studentPtrs[i] = nullptr;
    }

    return 0;
}
