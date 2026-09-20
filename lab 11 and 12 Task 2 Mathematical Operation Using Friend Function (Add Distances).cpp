#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance(int f = 0, float in = 0.0) : feet(f), inches(in) {}

    // Friend function declaration
    friend void addDistance(Distance d1, Distance d2);
};

// Friend function definition
void addDistance(Distance d1, Distance d2) {
    int totalFeet = d1.feet + d2.feet;
    float totalInches = d1.inches + d2.inches;

    // Convert excess inches to feet
    if (totalInches >= 12.0) {
        totalFeet += (int)(totalInches / 12);
        totalInches = (int)totalInches % 12 + (totalInches - (int)totalInches);
    }

    cout << "Total Distance: " << totalFeet << " feet " << totalInches << " inches" << endl;
}

int main() {
    Distance dist1(5, 8.5);
    Distance dist2(3, 6.2);

    addDistance(dist1, dist2);

    return 0;
}
