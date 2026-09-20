#include <iostream>
using namespace std;

// Function template returning the smaller of two values
template <typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    cout << "--- Finding Minimum Values ---" << endl;
    cout << "Min (15, 42): " << findMin(15, 42) << endl;
    cout << "Min (8.4, 2.3): " << findMin(8.4, 2.3) << endl;
    cout << "Min ('x', 'c'): " << findMin('x', 'c') << endl;

    return 0;
}
