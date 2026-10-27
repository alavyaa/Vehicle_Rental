#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

class Vehicle {
private:
    string vehicleID;
    string model;
    int rentalDuration;

public:
 
    Vehicle(string id, string m, int duration) {
        vehicleID = id;
        model = m;
        rentalDuration = duration;
    }

    string getVehicleID() const {
        return vehicleID;
    }

    string getModel() const {
        return model;
    }

    int getRentalDuration() const {
        return rentalDuration;
    }

    virtual double calculateRentalCharge() const = 0;

    virtual void displayDetails() const {
        cout << "\nVehicle ID       : " << vehicleID;
        cout << "\nModel            : " << model;
        cout << "\nRental Duration  : "
             << rentalDuration << " hour";
    }

    virtual ~Vehicle() {}
};


class Car : public Vehicle {
private:
    double ratePerHour;

public:
    Car(string id, string m, int duration)
        : Vehicle(id, m, duration) {
        ratePerHour = 600.0;
    }

    double calculateRentalCharge() const override {
        return ratePerHour * getRentalDuration();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "\nRate Per Hour    : Rs. "
             << ratePerHour;
        cout << "\nTotal Charges    : Rs. "
             << calculateRentalCharge() << "\n";
    }
};


class Bike : public Vehicle {
private:
    double ratePerHour;

public:
    Bike(string id, string m, int duration)
        : Vehicle(id, m, duration) {
        ratePerHour = 300.0;
    }

    double calculateRentalCharge() const override {
        return ratePerHour * getRentalDuration();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "\nRate Per Hour    : Rs. "
             << ratePerHour;
        cout << "\nTotal Charges    : Rs. "
             << calculateRentalCharge() << "\n";
    }
};

int main() {
    int choice;
    string vehicleID, model;
    int duration;

    cout << fixed << setprecision(2);


    while (true) {
        cout << "\n1. Rent a Car";
        cout << "\n2. Rent a Bike";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 3) {
            cout << "\nThank you!\n";
            break;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice! Please select 1, 2 or 3.\n";
            continue;
        }

        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;

        cout << "Enter Vehicle Model (one word): ";
        cin >> model;

        cout << "Enter rental duration in hours: ";

        if (!(cin >> duration)) {
            cout << "Invalid duration! Enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (duration <= 0) {
            cout << "Duration must be greater than zero.\n";
            continue;
        }

        Vehicle* vehicle = nullptr;

        if (choice == 1) {
            vehicle = new Car(vehicleID, model, duration);
        } else {
            vehicle = new Bike(vehicleID, model, duration);
        }

        vehicle->displayDetails();

        delete vehicle;
        vehicle = nullptr;
    }

    return 0;
}
