/*

AIRLINE SYSTEM

*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

using namespace std;

// ==========================================
// 1. VEHICLE BASE CLASS & DERIVED CLASSES
// ==========================================
class Vehicle {
protected:
    string id;
    string makeModel;
    double dailyRate;
    bool available;

public:
    Vehicle(string id, string makeModel, double dailyRate)
        : id(id), makeModel(makeModel), dailyRate(dailyRate), available(true) {}

    virtual ~Vehicle() = default;

    string getId() const { return id; }
    string getMakeModel() const { return makeModel; }
    double getDailyRate() const { return dailyRate; }
    bool isAvailable() const { return available; }

    void setAvailable(bool status) { available = status; }

    // Virtual Function for Runtime Polymorphism
    virtual double calculateRentalCost(int days) const {
        return dailyRate * days;
    }

    virtual void printDetails() const {
        cout << "[" << id << "] " << left << setw(18) << makeModel 
             << " | Rate: $" << setw(6) << dailyRate 
             << " | Status: " << (available ? "Available" : "Rented");
    }
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car(string id, string makeModel, double dailyRate, int seats)
        : Vehicle(id, makeModel, dailyRate), seats(seats) {}

    void printDetails() const override {
        Vehicle::printDetails();
        cout << " | Seats: " << seats << endl;
    }
};

class Motorbike : public Vehicle {
private:
    bool hasHelmetIncluded;

public:
    Motorbike(string id, string makeModel, double dailyRate, bool helmet)
        : Vehicle(id, makeModel, dailyRate), hasHelmetIncluded(helmet) {}

    // 10% discount if rental is longer than 7 days
    double calculateRentalCost(int days) const override {
        double total = dailyRate * days;
        if (days > 7) {
            total *= 0.90; // 10% discount
        }
        return total;
    }

    void printDetails() const override {
        Vehicle::printDetails();
        cout << " | Helmet: " << (hasHelmetIncluded ? "Yes" : "No") << endl;
    }
};

class Truck : public Vehicle {
private:
    double payloadCapacityTonnes;

public:
    Truck(string id, string makeModel, double dailyRate, double payload)
        : Vehicle(id, makeModel, dailyRate), payloadCapacityTonnes(payload) {}

    // 20% surcharge on top of total base daily rate
    double calculateRentalCost(int days) const override {
        double baseTotal = dailyRate * days;
        return baseTotal * 1.20; // 20% surcharge
    }

    void printDetails() const override {
        Vehicle::printDetails();
        cout << " | Payload: " << payloadCapacityTonnes << " Tons" << endl;
    }
};

// ==========================================
// 2. CUSTOMER CLASS
// ==========================================
class Customer {
private:
    string id;
    string name;
    bool hasActiveRental;

public:
    Customer(string id, string name) 
        : id(id), name(name), hasActiveRental(false) {}

    string getId() const { return id; }
    string getName() const { return name; }
    bool canRent() const { return !hasActiveRental; }

    void setHasActiveRental(bool status) { hasActiveRental = status; }
};

// ==========================================
// 3. RENTAL TRANSACTION RECORD CLASS
// ==========================================
class Rental {
private:
    static int idCounter;
    int rentalId;
    shared_ptr<Customer> customer;
    shared_ptr<Vehicle> vehicle;
    int days;
    double totalCost;
    bool active;

public:
    Rental(shared_ptr<Customer> cust, shared_ptr<Vehicle> veh, int days, double cost)
        : customer(cust), vehicle(veh), days(days), totalCost(cost), active(true) {
        rentalId = ++idCounter;
    }

    int getRentalId() const { return rentalId; }
    shared_ptr<Customer> getCustomer() const { return customer; }
    shared_ptr<Vehicle> getVehicle() const { return vehicle; }
    bool isActive() const { return active; }

    void closeRental() { active = false; }

    void printSummary() const {
        cout << "Rental #" << rentalId << " | Customer: " << setw(12) << customer->getName()
             << " | Vehicle: " << setw(15) << vehicle->getMakeModel()
             << " | Days: " << setw(2) << days
             << " | Total: $" << fixed << setprecision(2) << totalCost
             << " | Status: " << (active ? "ACTIVE" : "CLOSED") << endl;
    }
};

int Rental::idCounter = 0;

// ==========================================
// 4. CENTRAL RENTAL SYSTEM CLASS
// ==========================================
class RentalSystem {
private:
    vector<shared_ptr<Vehicle>> fleet;
    vector<shared_ptr<Customer>> customers;
    vector<shared_ptr<Rental>> rentals;

public:
    void addVehicle(shared_ptr<Vehicle> v) {
        fleet.push_back(v);
    }

    void registerCustomer(shared_ptr<Customer> c) {
        customers.push_back(c);
    }

    shared_ptr<Vehicle> findVehicle(const string& id) {
        for (auto& v : fleet) {
            if (v->getId() == id) return v;
        }
        return nullptr;
    }

    shared_ptr<Customer> findCustomer(const string& id) {
        for (auto& c : customers) {
            if (c->getId() == id) return c;
        }
        return nullptr;
    }

    // Process Rental
    bool processRental(const string& customerId, const string& vehicleId, int days) {
        auto cust = findCustomer(customerId);
        auto veh = findVehicle(vehicleId);

        if (!cust) {
            cout << "[Error] Customer ID " << customerId << " not found!" << endl;
            return false;
        }
        if (!veh) {
            cout << "[Error] Vehicle ID " << vehicleId << " not found!" << endl;
            return false;
        }
        if (!cust->canRent()) {
            cout << "[Denied] Customer " << cust->getName() << " already has an active rental." << endl;
            return false;
        }
        if (!veh->isAvailable()) {
            cout << "[Denied] Vehicle " << veh->getMakeModel() << " is currently unavailable." << endl;
            return false;
        }

        // Polymorphic Call: Calls overridden calculateRentalCost() dynamically
        double cost = veh->calculateRentalCost(days);

        // Update states
        veh->setAvailable(false);
        cust->setHasActiveRental(true);

        auto rental = make_shared<Rental>(cust, veh, days, cost);
        rentals.push_back(rental);

        cout << "[Success] Processed rental for " << cust->getName() 
             << " (" << veh->getMakeModel() << ") for " << days << " days. Total: $" << cost << endl;
        return true;
    }

    // Return Vehicle
    bool returnVehicle(int rentalId) {
        for (auto& r : rentals) {
            if (r->getRentalId() == rentalId && r->isActive()) {
                r->closeRental();
                r->getVehicle()->setAvailable(true);
                r->getCustomer()->setHasActiveRental(false);

                cout << "[Success] Vehicle " << r->getVehicle()->getMakeModel() 
                     << " returned by " << r->getCustomer()->getName() << "." << endl;
                return true;
            }
        }
        cout << "[Error] Active Rental ID " << rentalId << " not found." << endl;
        return false;
    }

    // Print System Summary
    void printSummary() const {
        cout << "\n=======================================================" << endl;
        cout << "                VEHICLE RENTAL SYSTEM SUMMARY          " << endl;
        cout << "=======================================================" << endl;

        // Fleet Counts
        int availableCount = 0, rentedCount = 0;
        for (const auto& v : fleet) {
            if (v->isAvailable()) availableCount++;
            else rentedCount++;
        }

        cout << "FLEET STATUS: Total: " << fleet.size() 
             << " | Available: " << availableCount 
             << " | Currently Rented: " << rentedCount << endl;

        cout << "\n--- FLEET DETAILS ---" << endl;
        for (const auto& v : fleet) {
            v->printDetails();
        }

        cout << "\n--- ALL RENTAL RECORDS ---" << endl;
        if (rentals.empty()) {
            cout << "No rental records found." << endl;
        } else {
            for (const auto& r : rentals) {
                r->printSummary();
            }
        }
        cout << "=======================================================\n" << endl;
    }
};

// ==========================================
// 5. MAIN DEMO SCENARIO
// ==========================================
int main() {
    RentalSystem system;

    // 1. Add Fleet (At least 3 types: Car, Motorbike, Truck)
    auto c1 = make_shared<Car>("C101", "Civic", 50.0, 5);
    auto m1 = make_shared<Motorbike>("M201", "Yamaha Heavy", 30.0, true);
    auto t1 = make_shared<Truck>("T301", "Isuzu D-Max", 100.0, 3.5);

    system.addVehicle(c1);
    system.addVehicle(m1);
    system.addVehicle(t1);

    // 2. Register Customers
    auto cust1 = make_shared<Customer>("U1", "Ali Marwat");
    auto cust2 = make_shared<Customer>("U2", "Junaid Khan");

    system.registerCustomer(cust1);
    system.registerCustomer(cust2);

    cout << "=======================================================" << endl;
    cout << "             STARTING RENTAL SYSTEM DEMO               " << endl;
    cout << "=======================================================\n" << endl;

    // 3. Process Rentals
    cout << "--- Processing Rental 1 (Car - 3 Days) ---" << endl;
    system.processRental("U1", "C101", 3);

    cout << "\n--- Processing Rental 2 (Truck - 5 Days with 20% Surcharge) ---" << endl;
    system.processRental("U2", "T301", 5);

    // Testing Prevention Requirement (Try renting already rented vehicle)
    cout << "\n--- Attempting duplicate rental on same vehicle ---" << endl;
    system.processRental("U1", "C101", 2);

    // Print Mid-State Summary
    system.printSummary();

    // 4. Return Vehicle
    cout << "--- Returning Rental #1 (Car) ---" << endl;
    system.returnVehicle(1);

    // 5. Print Final System Summary
    system.printSummary();

    return 0;
}
