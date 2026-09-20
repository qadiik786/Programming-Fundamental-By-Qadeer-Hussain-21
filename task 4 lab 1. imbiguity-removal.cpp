#include <iostream>
#include <string>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    float marks;

    // 1. Name Ambiguity Resolver: 'this->' differentiates member variables from parameters
    void setDetails(string firstName, string lastName, int rollNumber, float marks) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->rollNumber = rollNumber;
        this->marks = marks;
    }

    // 2. Method Chaining: Returning '*this' allows chaining multiple function calls
    Student& setMarks(float marks) {
        this->marks = marks;
        return *this; // Returns reference to the current object
    }

    void displayStudentInfo() {
        cout << "Full Name: " << this->firstName << " " << this->lastName << endl;
        cout << "Roll Number: " << this->rollNumber << endl;
        cout << "Marks: " << this->marks << endl;
    }
};

int main() {
    Student s;

    // Setting values using 'this' pointer inside function
    s.setDetails("Ali", "Khan", 101, 85.5);

    cout << "--- Initial Student Data ---" << endl;
    s.displayStudentInfo();

    // Updating marks using Method Chaining via 'this' pointer
    s.setMarks(92.0);

    cout << "\n--- Updated Student Data ---" << endl;
    s.displayStudentInfo();

    return 0;
}	
