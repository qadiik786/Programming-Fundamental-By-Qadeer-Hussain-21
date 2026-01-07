#include <iostream>
using namespace std;

int main() {
    double temps[7];
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    double sum = 0, highest;
    
    for (int i = 0; i < 7; i++) {
        cout << "Enter temperature for " << days[i] << ": ";
        cin >> temps[i];
        sum += temps[i];
        if (i == 0) highest = temps[i];
        else if (temps[i] > highest) highest = temps[i];
    }
    
    double average = sum / 7;
    cout << "\nAverage temperature: " << average << endl;
    cout << "Highest temperature: " << highest << endl;
    
    return 0;
}
