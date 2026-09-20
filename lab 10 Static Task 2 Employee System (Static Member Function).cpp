#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empID;
    string empName;

public:
    // Static data member
    static string companyName;

    Employee(int id, string name) : empID(id), empName(name) {}

    void displayEmployee() const {
        cout << "ID: " << empID << " | Name: " << empName << " | Company: " << companyName << endl;
    }

    // Static member function
    static void displayCompanyInfo() {
        cout << "Company Name: " << companyName << endl;
    }
};

// Definition of static variable
string Employee::companyName = "TechSolutions Corp";

int main() {
    // Calling static function via class name
    Employee::displayCompanyInfo();
    cout << "-----------------------------------" << endl;

    Employee e1(101, "Qadeer");
    Employee e2(102, "Usman");

    e1.displayEmployee();
    e2.displayEmployee();

    return 0;
}
