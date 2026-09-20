#include <iostream>
using namespace std;

class Temperature {
public:
    // Public data member to store temperature in Celsius
    float celsius;

    // Formula: Fahrenheit = (Celsius * 9/5) + 32
    float convertToFahrenheit() {
        return (celsius * 9.0 / 5.0) + 32;
    }

    void display() {
        cout << celsius << " Celsius is equal to " << convertToFahrenheit() << " Fahrenheit." << endl;
    }
};

int main() {
    Temperature temp;

    cout << "Enter Temperature in Celsius: ";
    cin >> temp.celsius;

    cout << "\n--- Temperature Conversion ---" << endl;
    temp.display();

    return 0;
}
