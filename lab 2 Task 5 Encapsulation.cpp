#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    // Private data members (Encapsulation)
    string name;
    double price;
    int quantity;

public:
    // Default Constructor to initialize default values
    Product() {
        name = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    // Setters with validation logic
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Error: Name cannot be empty!" << endl;
        }
    }

    void setPrice(double p) {
        if (p > 0) {
            price = p;
        } else {
            cout << "Error: Price must be greater than 0!" << endl;
        }
    }

    void setQuantity(int q) {
        if (q >= 0) {
            quantity = q;
        } else {
            cout << "Error: Quantity cannot be negative!" << endl;
        }
    }

    // Getters for accessing private attributes
    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }
};

int main() {
    // Creating object of Product class
    Product p;

    // Testing validation logic (Invalid Inputs)
    p.setName("");          // Should print error message
    p.setPrice(-50);        // Should print error message
    p.setQuantity(-2);      // Should print error message

    cout << "-----------------------------------" << endl;

    // Testing with valid data
    p.setName("Laptop");
    p.setPrice(1200.50);
    p.setQuantity(5);

    // Displaying output using getters
    cout << "Product: " << p.getName() << endl;
    cout << "Price: $" << p.getPrice() << endl;
    cout << "Quantity: " << p.getQuantity() << endl;

    return 0;
}
