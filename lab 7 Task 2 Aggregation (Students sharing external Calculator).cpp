#include <iostream>
using namespace std;

// Independent Class
class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double multiply(double a, double b) {
        return a * b;
    }
};

// Aggregation Class (Refers to shared Calculator)
class Student {
private:
    Calculator* calc; // Aggregation: Pointer to shared external object

public:
    Student(Calculator* c) : calc(c) {}

    void solveAddition(double a, double b) {
        if (calc) {
            cout << "Addition result: " << calc->add(a, b) << endl;
        }
    }

    void solveMultiplication(double a, double b) {
        if (calc) {
            cout << "Multiplication result: " << calc->multiply(a, b) << endl;
        }
    }
};

int main() {
    // Shared Calculator created independently
    Calculator myCalculator;

    // Passing pointer to multiple students
    Student s1(&myCalculator);
    Student s2(&myCalculator);

    cout << "--- Student 1 ---" << endl;
    s1.solveAddition(8, 3);
    s1.solveMultiplication(4, 5);

    cout << "\n--- Student 2 ---" << endl;
    s2.solveAddition(10, 2);
    s2.solveMultiplication(6, 7);

    return 0;
}
