#include <iostream>
using namespace std;

double calculatePercentage(int marks[]) {
    int total = 0;
    for (int i = 0; i < 5; i++) total += marks[i];
    return total / 5.0;
}

void displayResult(double percentage) {
    cout << "\nPercentage: " << percentage << "%\n";
    cout << "Grade: ";
    
    if (percentage >= 90) cout << "A+";
    else if (percentage >= 80) cout << "A";
    else if (percentage >= 70) cout << "B";
    else if (percentage >= 60) cout << "C";
    else cout << "Fail";
    cout << endl;
}

int main() {
    int marks[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for subject " << i+1 << ": ";
        cin >> marks[i];
    }
    
    double percentage = calculatePercentage(marks);
    displayResult(percentage);
    
    return 0;
}
