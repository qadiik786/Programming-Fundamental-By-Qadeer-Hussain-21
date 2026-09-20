#include <iostream>
#include <string>
using namespace std;

// Base Class
class Device {
protected:
    string deviceName;
    int deviceID;
    int* data; // Dynamic memory member

public:
    Device(string name, int id, int dVal) : deviceName(name), deviceID(id) {
        data = new int(dVal);
        cout << "[Device] Memory allocated for Base Data." << endl;
    }

    virtual ~Device() {
        delete data; // Free base memory
        cout << "[Device] Memory freed for Base Data." << endl;
    }
};

// Derived Class
class Sensor : public Device {
private:
    string sensorType;
    float* sensorValue; // Dynamic memory member

public:
    Sensor(string name, int id, int dVal, string type, float val) 
        : Device(name, id, dVal), sensorType(type) {
        sensorValue = new float(val);
        cout << "[Sensor] Memory allocated for Sensor Value." << endl;
    }

    ~Sensor() override {
        delete sensorValue; // Free derived memory
        cout << "[Sensor] Memory freed for Sensor Value." << endl;
    }

    void displaySensor() {
        cout << "Device Name: " << deviceName << " | ID: " << deviceID << endl;
        cout << "Type: " << sensorType << " | Value: " << *sensorValue << endl;
    }
};

int main() {
    cout << "--- Dynamic Memory Allocation (Heap) ---" << endl;
    Sensor* s1 = new Sensor("TempSensor", 101, 500, "Temperature", 36.5f);
    
    cout << "\n--- Sensor Details ---" << endl;
    s1->displaySensor();

    cout << "\n--- Dynamic Memory Deallocation ---" << endl;
    delete s1; // Calls derived destructor (~Sensor) first, then base destructor (~Device)

    return 0;
}
