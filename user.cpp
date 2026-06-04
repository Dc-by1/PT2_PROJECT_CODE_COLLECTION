#include "user.hpp"

// User Class Implementations
User::User(string r, string p, string s) : role(r), password(p), driverStatus(s) {}

User::~User() {
    cout << "[SYSTEM] User object (" << role << ") destroyed." << endl;
}

// Accessors
string User::getRole() const { return role; }
string User::getPassword() const { return password; }
string User::getDriverStatus() const { return driverStatus; }

// Mutators
void User::setRole(string r) { role = r; }
void User::setPassword(string p) { password = p; }
void User::setDriverStatus(string s) { driverStatus = s; }

// Login logic
bool User::login() {
    if (role == "Admin") {
        string input;
        cout << "Enter Admin Password: ";
        cin >> input;
        if (input == password) {
            cout << "[SUCCESS] Admin Authenticated." << endl;
            return true;
        } else {
            cout << "[ERROR] Incorrect password." << endl;
            return false;
        }
    } else {
        cout << "[INFO] Driver access granted (No password required)." << endl;
        return true;
    }
}

//Display Menu for Admin and Driver
void User::displayMenu() const {
    if (role == "Admin") {
        cout << "\n--- ADMIN DASHBOARD ---" << endl
             << "[1] View Parking Map" << endl
             << "[2] Manage Slot Maintenance" << endl
             << "[3] Generate Revenue & Audit Report" << endl
             << "[4] Search Vehicle by Plate" << endl
             << "[5] Change Password" << endl
             << "[6] Return to Main Menu" << endl; 
    } else {
        cout << "\n--- DRIVER MENU ---" << endl
             << "[1] Enter Parking" << endl
             << "[2] Exit Parking" << endl
             << "[3] Check Status" << endl
             << "[4] Report Issue" << endl
             << "[5] Return to Main Menu" << endl;
    }
}

//Allow admin to change the password
bool User::changePassword(string oldPw, string newPw) {
    if (oldPw == password) {
        password = newPw;
        cout << "[SUCCESS] Password changed successfully." << endl;
        return true;
    }
    cout << "[ERROR] Old password incorrect." << endl;
    return false;
}

//Call printRevenueReport in InvoiceSystem to show the revenue report to the admin
void User::generateReport(const InvoiceSystem& inv) const {
    if (role == "Admin") {
        inv.printRevenueReport(); 
    }
}

//Call searchVehicle in ParkingLot to allow the admin to search for a particular vehicle
void User::searchVehicle(ParkingLot* lot, string plateNum) const {
    if (role == "Admin" && lot != NULL) {
        lot->searchVehicle(plateNum); 
    }
}

//Allow driver to see the availability of parking slots
void User::checkStatus(ParkingLot& lot, const PricingCalculator& calc) const {
    if (role == "Driver") {
        cout << "[INFO] Checking status for a " << driverStatus << " driver." << endl;
        
        cout << "[INFO] Connected to real Parking Lot. Total capacity: " 
             << (lot.getRows() * lot.getCols()) << " slots." << endl;
             
        cout << "[INFO] Linked to Pricing Calculator. Daily Cap is: RM " << calc.getDailyCap() << endl;
    }
}

//Allow driver to report issue to the admin
void User::reportIssue(const InvoiceSystem& inv, string issueDesc) const {
    if (role == "Driver") {
        inv.appendAuditRecord("DRIVER ISSUE: " + issueDesc);
        cout << "[SUCCESS] Issue reported to Daily_Audit_Log.txt" << endl;
    }
}