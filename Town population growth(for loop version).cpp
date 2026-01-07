#include <iostream>
using namespace std;

int main() {
    int popA, popB;
    double rateA, rateB;
    
    cout << "Enter population of town A: ";
    cin >> popA;
    cout << "Enter growth rate of town A (%): ";
    cin >> rateA;
    cout << "Enter population of town B: ";
    cin >> popB;
    cout << "Enter growth rate of town B (%): ";
    cin >> rateB;
    
    int years = 0;
    double currentA = popA, currentB = popB;
    
    for (; currentA < currentB; years++) {
        currentA += currentA * (rateA / 100);
        currentB += currentB * (rateB / 100);
    }
    
    cout << "\nAfter " << years << " years:\n";
    cout << "Town A population: " << currentA << endl;
    cout << "Town B population: " << currentB << endl;
    
    return 0;
}
