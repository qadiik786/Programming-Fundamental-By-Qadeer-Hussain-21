#include <iostream>
using namespace std;

// Class owned by Calculator
class Display {
private:
    double lastValue;

public:
    Display() : lastValue(0.0) {}

    void show(double value) {
        lastValue = value;
        cout << "Result: " << lastValue << endl;
    }

    double getLastValue() const {
        return lastValue;
    }
};

// Composition Class (Owns Display)
class Calculator {
private:
    Display screen; // Composition: Display object created inside Calculator

public:
    Calculator() {}

    void add(double a, double b) {
        double result = a + b;
        screen.show(result);
    }

    void multiply(double a, double b) {
        double result = a * b;
        screen.show(result);
    }

    void showPreviousResult() const {
        cout << "Previous result: " << screen.getLastValue() << endl;
    }
};

int main() {
    Calculator calc;

    calc.add(10, 5);            // Output: Result: 15
    calc.multiply(3, 7);        // Output: Result: 21
    calc.showPreviousResult();  // Output: Previous result: 21

    return 0;
}
