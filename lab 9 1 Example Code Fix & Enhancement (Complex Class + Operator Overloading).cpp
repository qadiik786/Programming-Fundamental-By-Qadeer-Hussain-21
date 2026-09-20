#include <iostream>
using namespace std;

class Complex {
public:
    double real;
    double imag;

    // Default Constructor
    Complex() {
        real = 0.0;
        imag = 0.0;
    }

    // Parameterized Constructor
    Complex(double real, double imag) {
        this->real = real;
        this->imag = imag;
    }

    // Overloading + Operator
    Complex operator + (const Complex& c) {
        Complex ans;
        ans.real = this->real + c.real;
        ans.imag = this->imag + c.imag;
        return ans;
    }

    void printComplexNumber() {
        cout << this->real << " + " << this->imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.3, 3.2);
    Complex c2(4.0, 4.5);

    // Using overloaded + operator
    Complex c3 = c1 + c2;

    cout << "Sum of Complex Numbers: ";
    c3.printComplexNumber(); // Output: 6.3 + 7.7i

    return 0;
}
