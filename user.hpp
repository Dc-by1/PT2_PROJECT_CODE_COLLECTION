#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>

#include "PricingCalculator.hpp"
#include "InvoiceSystem.hpp"
#include "ParkingLot.hpp"

using namespace std;

//User Class
class User {
private:
    string role;
    string password;
    string driverStatus;

public:
    //Constructor and Destructor
    User(string r, string p = "", string s = "Standard");
    ~User();

    //Accessors 
    string getRole() const;
    string getPassword() const;
    string getDriverStatus() const;
    
    //Mutators 
    void setRole(string r);
    void setPassword(string p);
    void setDriverStatus(string s);

    
    bool login();
    void displayMenu() const;
    bool changePassword(string oldPw, string newPw);
    void generateReport(const InvoiceSystem& inv) const;
    void searchVehicle(ParkingLot* lot, string plateNum) const;
    void checkStatus(ParkingLot& lot, const PricingCalculator& calc) const;
    void reportIssue(const InvoiceSystem& inv, string issueDesc) const;
};

#endif