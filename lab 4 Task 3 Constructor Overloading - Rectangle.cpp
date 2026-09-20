#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    // 1. Default Constructor
    Rectangle() {
        length = 1.0;
        width = 1.0;
    }

    // 2. Parameterized Constructor (2 parameters)
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    // 3. Single-parameter Constructor (Square)
    Rectangle(float side) {
        length = side;
        width = side;
    }

    // Function to calculate area
    float area() {
        return length * width;
    }

    // Function to display dimensions and area
    void display() {
        cout << "Length: " << length << ", Width: " << width 
             << " | Area: " << area() << endl;
    }
};

int main() {
    // Default constructor object
    Rectangle r1;
    cout << "Default Rectangle: ";
    r1.display();

    // Parameterized constructor object
    Rectangle r2(5.5, 3.2);
    cout << "Custom Rectangle: ";
    r2.display();

    // Single-parameter constructor object (Square)
    Rectangle r3(4.0);
    cout << "Square Rectangle: ";
    r3.display();

    return 0;
}
