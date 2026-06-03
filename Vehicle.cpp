#include "Vehicle.hpp"
#include <cctype>
#include <string>

using namespace std;

// Constructor: Uses initializer list
Vehicle::Vehicle(string plate, string type) {
    plateNumber = (formatPlateNumber(plate));
    vehicleType = type;
}

// Destructor
Vehicle::~Vehicle() {}

// Static utility: Capitalizes and strips spaces from raw plate input
string Vehicle::formatPlateNumber(string oriPlate) {
    string newPlate = "";
    for (size_t i = 0; i < oriPlate.size(); i++) {
        if (oriPlate[i] != ' ') {
            newPlate += toupper(oriPlate[i]);
        }
    }
    return newPlate;
}

// Accessors (Getters)
string Vehicle::getPlate() const {
    return plateNumber;
}

string Vehicle::getType() const {
    return vehicleType;
}

// Mutators (Setters)
void Vehicle::setPlate(string newPlate) {
    // Keeps data sanitized even when changed
    plateNumber = formatPlateNumber(newPlate); 
}

void Vehicle::setType(string newType) {
    vehicleType = newType;
}

// Functional Methods (Using Selection)

// Returns the correct base rate using selection logic
double Vehicle::getBaseRate() const {
    if (vehicleType == "Car") {
        return 2.00;
    } else if (vehicleType == "Motorcycle") {
        return 1.00;
    } else {
        return 0.00; // Default fallback for invalid types
    }
}

// Returns the required slot type using selection logic
string Vehicle::getSlotRequirement() const {
    if (vehicleType == "Car") {
        return "Car";
    } else if (vehicleType == "Motorcycle") {
        return "Motorcycle";
    } else {
        return "Unknown";
    }
}