#include <iostream>
using namespace std;

class Locker {
public:
    // Constructor
    Locker() {
        cout << "Locker allocated to customer." << endl;
    }

    // Destructor
    ~Locker() {
        cout << "Locker returned by customer." << endl;
    }
};

int main() {
    cout << "--- Stack Object Demonstration ---" << endl;
    {
        // Block scope to test automatic destructor call on stack
        Locker stackLocker; 
    } // stackLocker goes out of scope here -> Destructor called automatically

    cout << "\n--- Heap Object Demonstration ---" << endl;
    // Dynamic allocation using new on Heap
    Locker* heapLocker = new Locker();

    // Releasing memory using delete -> Calls destructor manually
    delete heapLocker;

    return 0;
}
