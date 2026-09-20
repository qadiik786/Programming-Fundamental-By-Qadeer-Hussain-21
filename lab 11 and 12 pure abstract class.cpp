#include <iostream>
#include <string>
using namespace std;

// Pure Abstract Class
class HospitalStaff {
protected:
    string staffName;

public:
    HospitalStaff(string name) : staffName(name) {}

    // Pure Virtual Function
    virtual void performDuty() = 0;

    virtual ~HospitalStaff() {}
};

// Derived Class 1: Doctor
class Doctor : public HospitalStaff {
public:
    Doctor(string name) : HospitalStaff(name) {}

    void performDuty() override {
        cout << "Doctor " << staffName << " is diagnosing patients." << endl;
    }
};

// Derived Class 2: Nurse
class Nurse : public HospitalStaff {
public:
    Nurse(string name) : HospitalStaff(name) {}

    void performDuty() override {
        cout << "Nurse " << staffName << " is assisting patients." << endl;
    }
};

// Derived Class 3: Receptionist
class Receptionist : public HospitalStaff {
public:
    Receptionist(string name) : HospitalStaff(name) {}

    void performDuty() override {
        cout << "Receptionist " << staffName << " is managing appointments." << endl;
    }
};

int main() {
    // Array of base class pointers for polymorphic behavior
    HospitalStaff* staff[3];

    staff[0] = new Doctor("Dr. Ahmed");
    staff[1] = new Nurse("Sara");
    staff[2] = new Receptionist("Bilal");

    cout << "--- Hospital Staff Duties ---" << endl;
    for (int i = 0; i < 3; i++) {
        staff[i]->performDuty();
    }

    // Memory cleanup
    for (int i = 0; i < 3; i++) {
        delete staff[i];
    }

    return 0;
}
