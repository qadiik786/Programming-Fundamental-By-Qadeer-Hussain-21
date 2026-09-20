#include <iostream>
using namespace std;

class Rectangle {
    int length;
    int width;

public:
    // Function declarations inside class
    void setDimensions(int l, int w);
    int area();
    int perimeter();
};

// Function definitions OUTSIDE class using scope resolution operator (::)
void Rectangle::setDimensions(int l, int w) {
    length = l;
    width = w;
}

int Rectangle::area() {
    return length * width;
}

int Rectangle::perimeter() {
    return 2 * (length + width);
}

int main() {
    Rectangle rect;
    int l, w;

    cout << "Enter Length of Rectangle: ";
    cin >> l;
    cout << "Enter Width of Rectangle: ";
    cin >> w;

    rect.setDimensions(l, w);
    cout << "\nArea of Rectangle: " << rect.area() << endl;
    cout << "Perimeter of Rectangle: " << rect.perimeter() << endl;

    return 0;
}
