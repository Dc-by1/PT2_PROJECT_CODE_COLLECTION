#include "User.hpp"
#include <iostream>

using namespace std;

int main() {
    ParkingLot Lot(3, 5); //create 3x5 parking lot
    Lot.initializeMockData();    

    PricingCalculator Calc(30.0); //create calculator with RM 30 cap
    InvoiceSystem Invoice;        

    //ask user for Admin Password
    cout << "=== SYSTEM INITIALIZATION ===" << endl;
    
    //create users (Admin and Driver)
    User adminUser("Admin", "admin123");
    User driverUser("Driver", "", "Standard");

    int userType = 0;
    
    //main Logic for class User 
    bool loop = true;
    while (loop == true) {
        cout << "\n=========================================" << endl;
        cout << "      SMART PARKING MANAGEMENT SYSTEM    " << endl;
        cout << "=========================================" << endl;
        cout << "[1] Login as Admin\n"
             << "[2] Login as Driver\n"     
             << "[3] Exit System\nSelection: ";
        cin >> userType;

        if (userType == 1) { //ADMIN FLOW
            bool loggedIn = false;
            do {
                loggedIn = adminUser.login(); 
            } while (!loggedIn);

            int choice = 0;
            while (choice != 6) {
                adminUser.displayMenu();
                cout << "Selection: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "[Calling displayMatrix() in ParkingLot] Displaying Parking Map..." << endl; //calling displayMatrix function in ParkingLot class
                } 
                
                else if (choice == 2) {
                    cout << "[Calling setMaintenanceStatus() in ParkingLot] Managing slot maintenance..." << endl; //calling setMaintenanceStatus function in ParkingLot class
                }
                
                else if (choice == 3) {
                    adminUser.generateReport(Invoice); 
                } 
                
                else if (choice == 4) {
                    cout << "Enter Plate to Search: ";
                    string plate;
                    cin >> plate;
                    adminUser.searchVehicle(&Lot, plate);
                } 
                
                else if (choice == 5) {
                    cout << "Enter Old Password: ";
                    string oldP, newP;
                    cin >> oldP;
                    cout << "Enter New Password: ";
                    cin >> newP;
                    adminUser.changePassword(oldP, newP);
                }
            }
        } 
        else if (userType == 2) { //DRIVER FLOW
            driverUser.login();
            int choice = 0;
            
            while (choice != 5) {
                driverUser.displayMenu();
                cout << "Selection: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "[Calling assignVehicle() in ParkingSlot] Entering parking..." << endl; //calling assignVehicle function in ParkingSlot class
                } 
                
                else if (choice == 2) {
                    cout << "[Calling clearSlot() in ParkingSlot] Exiting parking..." << endl; //calling clearSlot function in ParkingSlot class
                } 
                
                else if (choice == 3) {
                    driverUser.checkStatus(Lot, Calc); 
                } 
                
                else if (choice == 4) {
                    cin.ignore(); 
                    cout << "Enter Issue Description: ";
                    string issue;
                    getline(cin, issue);
                    driverUser.reportIssue(Invoice, issue); 
                }
            }
        } 
        else if (userType == 3) {
            cout << "Exiting Parking System!" << endl;
            loop = false;
        } 
        
        else {
            cout << "[ERROR] Invalid selection." << endl;
        }
    }

    return 0;
}