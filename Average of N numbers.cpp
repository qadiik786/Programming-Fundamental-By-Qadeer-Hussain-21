#include <iostream>
using namespace std;

int main() {
    int n;
    
    while (true) {
        cout << "How many numbers? (1-100): ";
        cin >> n;
        if (n >= 1 && n <= 100) break;
        cout << "Invalid! Enter between 1 and 100.\n";
    }
    
    double arr[100], sum = 0;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    
    cout << "Average = " << sum / n << endl;
    return 0;
}
