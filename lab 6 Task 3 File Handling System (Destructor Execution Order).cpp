#include <iostream>
using namespace std;

// Base Class
class File {
public:
    File() {
        cout << "Base: File opened" << endl;
    }
    
    // Virtual destructor ensuring correct cleanup in inheritance
    virtual ~File() {
        cout << "Base: File closed" << endl;
    }
};

// Derived Class
class TextFile : public File {
public:
    TextFile() {
        cout << "Derived: Text File initialized" << endl;
    }
    
    ~TextFile() override {
        cout << "Derived: Text File destroyed" << endl;
    }
};

int main() {
    cout << "--- Scope Block Start ---" << endl;
    {
        TextFile myFile;
        // Observe constructor order (Base -> Derived) and destructor order (Derived -> Base)
    }
    cout << "--- Scope Block End ---" << endl;

    return 0;
}
