#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    // Virtual function enables Dynamic Binding / Run-Time Polymorphism
    virtual void makeSound() {
        cout << "Animal makes a sound." << endl;
    }

    // Virtual Destructor for safe memory deallocation
    virtual ~Animal() {}
};

// Derived Class
class Dog : public Animal {
public:
    // Overriding base class method
    void makeSound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

int main() {
    cout << "--- Run-Time Polymorphism ---" << endl;
    
    // Base class pointer pointing to Derived class object
    Animal* a = new Dog();
    
    // Calls Dog's overridden function at runtime
    a->makeSound(); 

    // Cleanup
    delete a;

    return 0;
}
