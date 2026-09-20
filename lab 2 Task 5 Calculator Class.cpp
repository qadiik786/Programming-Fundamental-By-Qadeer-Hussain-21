#include <iostream>
using namespace std;

class Calculator {
    float num1;
    float num2;

public:
    void setNumbers(float a, float b) {
        num1 = a;
        num2 = b;
    }

    float add() { return num1 + num2; }
    float subtract() { return num1 - num2; }
    float multiply() { return num1 * num2; }
    float divide() {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    Calculator calc;
    float n1, n2;
    int choice;

    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;

    calc.setNumbers(n1, n2);

    cout << "\n--- Select Operation ---" << endl;
    cout << "1. Add (+)\n2. Subtract (-)\n3. Multiply (*)\n4. Divide (/)\n";
    cout << "Enter choice (1-4): ";
    cin >> choice;

    cout << "\nResult: ";
    switch (choice) {
        case 1: cout << calc.add(); break;
        case 2: cout << calc.subtract(); break;
        case 3: cout << calc.multiply(); break;
        case 4: cout << calc.divide(); break;
        default: cout << "Invalid Operation Choice!";
    }
    cout << endl;

    return 0;
}
/*Task 5 (Bonus): Header File Implementation Example:
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
    float num1;
    float num2;

public:
    void setNumbers(float a, float b);
    float add();
    float subtract();
    float multiply();
    float divide();
};

void Calculator::setNumbers(float a, float b) { num1 = a; num2 = b; }
float Calculator::add() { return num1 + num2; }
float Calculator::subtract() { return num1 - num2; }
float Calculator::multiply() { return num1 * num2; }
float Calculator::divide() { return (num2 != 0) ? (num1 / num2) : 0; }

int main() {
    Calculator c;
    c.setNumbers(12.5, 2.5);
    cout << "Sum using Header Structure: " << c.add() << endl;
    return 0;
}/*
