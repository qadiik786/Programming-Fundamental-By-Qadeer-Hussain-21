#include <iostream>
using namespace std;

int main() {
    int num, limit;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter limit: ";
    cin >> limit;
    
    cout << "Multiplication Table of " << num << ":\n";
    for (int i = 1; i <= limit; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
    return 0;
}
