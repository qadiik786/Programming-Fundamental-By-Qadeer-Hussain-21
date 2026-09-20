#include <iostream>
#include <string>
using namespace std;

// Base Class
class Product {
protected:
    string name;
    double price;

public:
    // Base class parameterized constructor
    Product(string n, double p) : name(n), price(p) {}

    void displayProduct() {
        cout << "Product Name: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived Class
class Electronics : public Product {
private:
    int warrantyYears;

public:
    // Constructor chaining to initialize base class members
    Electronics(string n, double p, int w) : Product(n, p), warrantyYears(w) {}

    void displayElectronics() {
        displayProduct();
        cout << "Warranty: " << warrantyYears << " Year(s)" << endl;
    }
};

int main() {
    Electronics laptop("Gaming Laptop", 1250.00, 2);
    cout << "--- Electronics Item Details ---" << endl;
    laptop.displayElectronics();

    return 0;
}
