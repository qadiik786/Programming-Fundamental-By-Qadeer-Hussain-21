#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
    }
    
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    
    cout << "Largest number = " << largest << endl;
    return 0;
}
