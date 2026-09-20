#include <iostream>
#include <string>
using namespace std;

// Class template storing two values of the same type
template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const {
        return first;
    }

    T getSecond() const {
        return second;
    }

    void display() const {
        cout << "First: " << first << " | Second: " << second << endl;
    }
};

int main() {
    cout << "--- Pair Class Template ---" << endl;

    Pair<int> intPair(10, 20);
    intPair.display();

    Pair<double> doublePair(5.5, 9.8);
    doublePair.display();

    Pair<string> stringPair("C++", "Templates");
    stringPair.display();

    return 0;
}
