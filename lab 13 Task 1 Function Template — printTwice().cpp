#include <iostream>
#include <string>
using namespace std;

// Function template printing the value twice
template <typename T>
void printTwice(T val) {
    cout << val << endl;
    cout << val << endl;
}

int main() {
    cout << "--- Printing Integer ---" << endl;
    printTwice(100);

    cout << "\n--- Printing Double ---" << endl;
    printTwice(99.99);

    cout << "\n--- Printing String ---" << endl;
    printTwice(string("Object Oriented Programming"));

    return 0;
}
