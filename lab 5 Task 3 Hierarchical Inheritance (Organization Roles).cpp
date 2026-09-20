#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    double salary;

public:
    void setEmployeeData(string n, double s) {
        name = n;
        salary = s;
    }

    void display_employee() {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Derived Class 1
class Developer : public Employee {
private:
    string programming_language;

public:
    void setDeveloperData(string n, double s, string lang) {
        setEmployeeData(n, s);
        programming_language = lang;
    }

    void display_developer() {
        display_employee();
        cout << "Programming Language: " << programming_language << endl;
    }
};

// Derived Class 2
class Designer : public Employee {
private:
    string design_tool;

public:
    void setDesignerData(string n, double s, string tool) {
        setEmployeeData(n, s);
        design_tool = tool;
    }

    void display_designer() {
        display_employee();
        cout << "Design Tool: " << design_tool << endl;
    }
};

int main() {
    Developer dev;
    dev.setDeveloperData("Ali", 85000.0, "C++");

    Designer des;
    des.setDesignerData("Fiona", 75000.0, "Figma");

    cout << "--- Developer Info ---" << endl;
    dev.display_developer();

    cout << "\n--- Designer Info ---" << endl;
    des.display_designer();

    return 0;
}
