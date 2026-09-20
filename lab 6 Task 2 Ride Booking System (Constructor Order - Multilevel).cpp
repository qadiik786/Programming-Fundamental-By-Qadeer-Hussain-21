#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle {
public:
    Vehicle(string type) {
        cout << "[Vehicle Constructor] Type: " << type << endl;
    }
};

// Intermediate Derived Class
class Car : public Vehicle {
public:
    Car(string type, string brand) : Vehicle(type) {
        cout << "[Car Constructor] Brand: " << brand << endl;
    }
};

// Final Derived Class
class ElectricCar : public Car {
public:
    ElectricCar(string type, string brand, int batteryCap) : Car(type, brand) {
        cout << "[ElectricCar Constructor] Battery Capacity: " << batteryCap << " kWh" << endl;
    }
};

int main() {
    cout << "--- Initializing ElectricCar Object ---" << endl;
    // Observing execution order from base to derived
    ElectricCar myEV("4-Wheeler", "Tesla", 75);

    return 0;
}
