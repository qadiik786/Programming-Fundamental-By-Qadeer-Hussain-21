#include <iostream>
using namespace std;

class Box {
private:
    double length;

public:
    Box(double l) : length(l) {}

    // Friend function declaration
    friend void displayLength(Box b);
};

// Friend function definition
void displayLength(Box b) {
    cout << "Length of the Box: " << b.length << " units" << endl;
}

int main() {
    Box myBox(15.5);
    displayLength(myBox); // Called like a normal function

    return 0;
}
