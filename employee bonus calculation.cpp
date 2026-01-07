#include <iostream>
using namespace std;

double calculateBonus(double salary, int rating) {
    double bonus = 0;
    if (rating == 5) bonus = salary * 0.20;
    else if (rating == 4) bonus = salary * 0.10;
    else if (rating == 3) bonus = salary * 0.05;
    return bonus;
}

void displayBonus(double salary, double bonus) {
    cout << "\nBonus Amount: $" << bonus << endl;
    cout << "Final Salary: $" << salary + bonus << endl;
}

int main() {
    double salary;
    int rating;
    
    cout << "Enter employee salary: ";
    cin >> salary;
    cout << "Enter performance rating (1-5): ";
    cin >> rating;
    
    double bonus = calculateBonus(salary, rating);
    displayBonus(salary, bonus);
    
    return 0;
}
