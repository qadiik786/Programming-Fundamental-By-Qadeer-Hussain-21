#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    // Constructor
    Distance(int f = 0, float in = 0.0) : feet(f), inches(in) {}

    // Overloading == Operator
    bool operator == (const Distance& d) {
        return (feet == d.feet) && (inches == d.inches);
    }

    void display() const {
        cout << feet << " feet " << inches << " inches";
    }
};

int main() {
    Distance d1(5, 8.5);
    Distance d2(5, 8.5);
    Distance d3(6, 2.0);

    cout << "Distance 1: "; d1.display(); cout << endl;
    cout << "Distance 2: "; d2.display(); cout << endl;
    cout << "Distance 3: "; d3.display(); cout << endl;

    cout << "\n--- Comparison Results ---" << endl;
    if (d1 == d2) {
        cout << "Distance 1 and Distance 2 are EQUAL." << endl;
    } else {
        cout << "Distance 1 and Distance 2 are NOT EQUAL." << endl;
    }

    if (d1 == d3) {
        cout << "Distance 1 and Distance 3 are EQUAL." << endl;
    } else {
        cout << "Distance 1 and Distance 3 are NOT EQUAL." << endl;
    }

    return 0;
}
