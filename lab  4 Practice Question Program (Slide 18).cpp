#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() { 
        cout << "Constructor" << endl; 
    }
    ~MyClass() { 
        cout << "Destructor" << endl; 
    }
};

int main() {
    MyClass obj;
    return 0;
}
