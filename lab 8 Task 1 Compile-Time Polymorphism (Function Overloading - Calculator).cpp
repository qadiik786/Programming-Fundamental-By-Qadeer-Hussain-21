#include <iostream>
using namespace std;

class Calculator {
public:
    // Overloaded method 1: Adds two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded method 2: Adds two double values
    double add(double a, double b) {
        return a + b;
    }

    // Overloaded method 3: Adds three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    cout << "--- Compile-Time Polymorphism ---" << endl;
    cout << "Addition of 2 Integers (2 + 3): " << calc.add(2, 3) << endl;
    cout << "Addition of 2 Doubles (2.5 + 3.5): " << calc.add(2.5, 3.5) << endl;
    cout << "Addition of 3 Integers (1 + 2 + 3): " << calc.add(1, 2, 3) << endl;

    return 0;
}
