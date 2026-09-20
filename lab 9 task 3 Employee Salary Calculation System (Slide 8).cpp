#include <iostream>
using namespace std;

// Base Class
class Employee {
public:
    virtual double calculateSalary() {
        cout << "Base Employee salary calculation called." << endl;
        return 0.0;
    }

    virtual ~Employee() {}
};

// Derived Class 1: Permanent Employee
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double bonus;

public:
    PermanentEmployee(double salary, double b) : basicSalary(salary), bonus(b) {}

    double calculateSalary() override {
        return basicSalary + bonus;
    }
};

// Derived Class 2: Contract Employee
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    // Base class pointers for Dynamic Polymorphism
    Employee* emp1 = new PermanentEmployee(40000, 5000);
    Employee* emp2 = new ContractEmployee(800, 30);

    cout << "--- Salary Calculations ---" << endl;
    cout << "Permanent Employee Salary: Rs. " << emp1->calculateSalary() << endl;
    cout << "Contract Employee Salary: Rs. " << emp2->calculateSalary() << endl;

    // Memory Cleanup
    delete emp1;
    delete emp2;

    return 0;
}
