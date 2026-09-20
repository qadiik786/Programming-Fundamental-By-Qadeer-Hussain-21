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
    cout << "Enter total number of students: ";
    cin >> count;

    // Array of structures
    Student students[100];

    // Input details for multiple students
    for (int i = 0; i < count; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":" << endl;
        cout << "First Name: ";
        cin >> students[i].firstName;
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Marks: ";
        cin >> students[i].marks;
    }

    // Display details for each student
    cout << "\n===============================" << endl;
    cout << "--- ALL STUDENTS RECORDS ---" << endl;
    cout << "===============================" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        students[i].displayStudentInfo();
        cout << "-------------------------------" << endl;
    }

    return 0;
}
