# include "ParkingSlot.hpp"
# include <iostream>
using namespace std;

// Constructor: Initialises the attributes using an initializer list
ParkingSlot::ParkingSlot(string id, string type): slotID(id), slotType(type), isOccupied(false), isUnderMaintenance(false), vehicle(nullptr) {}

ParkingSlot::~ParkingSlot() {}

// Sets the unique ID of the slot
void ParkingSlot::setSlotID(string id){   
    slotID = id;
}

// Sets the vehicle type for this slot
void ParkingSlot::setSlotType(string type){
    slotType = type;
}

// Sets the occupation status of the slot
void ParkingSlot::setIsOccupied(bool occupied){
    isOccupied = occupied;
}

//Sets maintenance status and clears the vehicle if marked under maintenance
void ParkingSlot::setMaintenance(bool status){
    isUnderMaintenance = status;
    if(isUnderMaintenance){
        vehicle = nullptr;
        isOccupied= false;
    }
}

// Directly maps a vehicle pointer to the slot member
void ParkingSlot::setVehicle(Vehicle *v){
    vehicle = v;
}

// Returns the slot's unique ID
string ParkingSlot::getSlotID() const{
    return slotID;
}

// Returns the slot's vehicle type 
string ParkingSlot::getSlotType() const{
    return slotType;
}

// Returns true if a vehicle is parked here
bool ParkingSlot::getIsOccupied() const{
    return isOccupied;
}

// Returns true if the slot is locked for maintenance
bool ParkingSlot::getIsUnderMaintenance() const{
    return isUnderMaintenance;
}

// Returns the pointer to the currently parked vehicle
const Vehicle* ParkingSlot::getVehicle() const{
    return vehicle;
}

//Links a vehicle to the slot and updates status
void ParkingSlot::assignVehicle(Vehicle *v){ //no checking slot type here because it will be checked in ParkingLot class then call this method
    vehicle = v;
    isOccupied = true;
}

//Unlinks the vehicle and updates status
void ParkingSlot::clearSlot(){
    vehicle = nullptr;
    isOccupied = false;
}

// Overloaded output operator to format the slot for display output
ostream& operator<<(ostream &out, const ParkingSlot& obj){
    if(obj.isUnderMaintenance){
        out<< "[ X ]";
    }
    else if(obj.isOccupied && obj.vehicle != nullptr){
        if(obj.vehicle->getSlotRequirement() == "Car"){
            out<<"[ C ]";
        }
        else{
            out<<"[ M ]";
        }
    }
    else{
        out<<"[   ]";
    }

    return out;
}