#include <iostream>
#include <cmath>
using namespace std;

// Base Class
class Shape {
public:
    // Virtual method returning default area 0
    virtual double area() const {
        return 0.0;
    }

    virtual ~Shape() {}
};

// Derived Class 1: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding area calculation for Rectangle
    double area() const override {
        return length * width;
    }
};

// Derived Class 2: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding area calculation for Circle
    double area() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    // Array of Shape pointers demonstrating polymorphism
    Shape* shapes[2];

    shapes[0] = new Rectangle(5.0, 4.0);
    shapes[1] = new Circle(3.0);

    cout << "--- Shape Area Calculations ---" << endl;
    cout << "Rectangle Area: " << shapes[0]->area() << endl;
    cout << "Circle Area: " << shapes[1]->area() << endl;

    // Free memory
    delete shapes[0];
    delete shapes[1];

    return 0;
}
