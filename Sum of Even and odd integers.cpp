#include <iostream>
using namespace std;

int main() {
    int n, num, evenSum = 0, oddSum = 0;
    
    cout << "How many integers? ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Enter integer " << i << ": ";
        cin >> num;
        if (num % 2 == 0)
            evenSum += num;
        else
            oddSum += num;
    }
    
    cout << "Sum of even numbers: " << evenSum << endl;
    cout << "Sum of odd numbers: " << oddSum << endl;
    
    return 0;
}
