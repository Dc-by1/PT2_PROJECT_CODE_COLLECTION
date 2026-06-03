#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
using namespace std;

class Vehicle {
private: 
    // Strictly private data members for encapsulation
    string plateNumber;
    string vehicleType; 

public:
    // Constructor and Destructor
    Vehicle(string plate, string type);
    ~Vehicle();

    // Static helper method
    static string formatPlateNumber(string rawPlate);

    // Accessors (Getters) marked const
    string getPlate() const;
    string getType() const;

    // Mutators (Setters)
    void setPlate(string newPlate);
    void setType(string newType);

    // Functional methods using if/else selection
    double getBaseRate() const;
    string getSlotRequirement() const;
};

#endif