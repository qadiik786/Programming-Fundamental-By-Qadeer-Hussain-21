#include <iostream>
using namespace std;

// Class template performing arithmetic operations
template <typename T>
class Calculator {
private:
    T a;
    T b;

public:
    Calculator(T x, T y) : a(x), b(y) {}

    T add() const {
        return a + b;
    }

    T subtract() const {
        return a - b;
    }

    T multiply() const {
        return a * b;
    }
};

int main() {
    // Testing with Integer values
    cout << "--- Integer Calculator (12, 4) ---" << endl;
    Calculator<int> intCalc(12, 4);
    cout << "Addition: " << intCalc.add() << endl;
    cout << "Subtraction: " << intCalc.subtract() << endl;
    cout << "Multiplication: " << intCalc.multiply() << endl;

    // Testing with Double values
    cout << "\n--- Double Calculator (10.5, 2.5) ---" << endl;
    Calculator<double> doubleCalc(10.5, 2.5);
    cout << "Addition: " << doubleCalc.add() << endl;
    cout << "Subtraction: " << doubleCalc.subtract() << endl;
    cout << "Multiplication: " << doubleCalc.multiply() << endl;

    return 0;
} 
