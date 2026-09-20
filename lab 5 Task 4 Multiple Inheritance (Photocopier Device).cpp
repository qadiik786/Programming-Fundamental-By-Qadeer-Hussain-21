#include <iostream>
using namespace std;

// Base Class 1
class Printer {
public:
    void print_document() {
        cout << "Printing document..." << endl;
    }
};

// Base Class 2
class Scanner {
public:
    void scan_document() {
        cout << "Scanning document..." << endl;
    }
};

// Derived Class from Printer & Scanner
class Photocopier : public Printer, public Scanner {
public:
    void photocopy() {
        cout << "Starting Photocopy Process:" << endl;
        scan_document();
        print_document();
    }
};

int main() {
    Photocopier copier;

    cout << "--- Direct Method Calls ---" << endl;
    copier.print_document();
    copier.scan_document();

    cout << "\n--- Photocopier Method Call ---" << endl;
    copier.photocopy();

    return 0;
}
