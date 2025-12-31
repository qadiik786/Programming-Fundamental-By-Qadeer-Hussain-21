#include <iostream>
using namespace std;

int main() {

    int age, choice;
    string name, city, disease, date, doctor;
    char gender;
    long long number;

    do {
        cout << "\n====== CMH APPOINTMENT SYSTEM ======\n";
        cout << "1. Book Appointment\n";
        cout << "2. Assign Doctor\n";
        cout << "3. Print Appointment Letter\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n--- Book Appointment ---\n";

            cout << "Name: ";
            getline(cin, name);

            cout << "Age: ";
            cin >> age;

            cout << "Phone Number: ";
            cin >> number;
            cin.ignore();

            cout << "Date (DD/MM/YYYY): ";
            getline(cin, date);

            cout << "Gender (M/F/O): ";
            cin >> gender;
            cin.ignore();

            cout << "City: ";
            getline(cin, city);

            cout << "Disease: ";
            getline(cin, disease);

            cout << "\nAppointment booked successfully!\n";
        }

        else if (choice == 2) {
            cout << "\n--- Assign Doctor ---\n";

            if (disease == "Fever")
                doctor = "Dr. Ahmad";
            else if (disease == "Heart Problem")
                doctor = "Dr. Khan";
            else if (disease == "Skin Allergy")
                doctor = "Dr. Ali";
            else
                doctor = "Dr. Aslam";

            cout << "Doctor Assigned: " << doctor << endl;
        }

        else if (choice == 3) {
            cout << "\n--- Appointment Letter ---\n";

            cout << "Patient Name: " << name << endl;
            cout << "Doctor: " << doctor << endl;
            cout << "Date: " << date << endl;
            cout << "Hospital: CMH Hospital\n";
            cout << "Please arrive 15 minutes early.\n";
        }

        else if (choice == 4) {
            cout << "\nSystem Closed. Allah Hafiz!\n";
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

