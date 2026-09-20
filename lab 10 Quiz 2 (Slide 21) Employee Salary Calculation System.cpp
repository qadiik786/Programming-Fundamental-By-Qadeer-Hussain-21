#include <iostream>
using namespace std;

// Base Class
class Employee {
public:
    virtual double calculateSalary() {
        return 0.0;
    }
    virtual ~Employee() {}
};

// FullTime Employee Class
class FullTime : public Employee {
private:
    double basicPay;
    double allowancePercent; // e.g., 20% -> 0.20
    double taxPercent;       // e.g., 10% -> 0.10

public:
    FullTime(double pay, double allowance, double tax) 
        : basicPay(pay), allowancePercent(allowance), taxPercent(tax) {}

    double calculateSalary() override {
        return basicPay + (basicPay * allowancePercent) - (basicPay * taxPercent);
    }
};

// PartTime Employee Class
class PartTime : public Employee {
private:
    double hoursWorked;
    double ratePerHour;

public:
    PartTime(double hours, double rate) : hoursWorked(hours), ratePerHour(rate) {}

    double calculateSalary() override {
        return hoursWorked * ratePerHour;
    }
};

int main() {
    // Basic Pay = 50000, Allowance = 20% (0.20), Tax = 10% (0.10)
    Employee* emp1 = new FullTime(50000, 0.20, 0.10);
    
    // Hours Worked = 40, Rate per Hour = 500
    Employee* emp2 = new PartTime(40, 500);

    cout << "--- Employee Salary Calculation ---" << endl;
    cout << "Full-Time Employee Salary: Rs. " << emp1->calculateSalary() << endl;
    cout << "Part-Time Employee Salary: Rs. " << emp2->calculateSalary() << endl;

    delete emp1;
    delete emp2;

    return 0;
}
