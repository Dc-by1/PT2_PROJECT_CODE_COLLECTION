# ifndef PARKINGSLOT_HPP
# define PARKINGSLOT_HPP
# include "Vehicle.hpp"
# include <string>
using namespace std;

// Purpose: Represents an individual parking slot in the system

class ParkingSlot{
    private:
        string slotID;            // Unique identifier for the slot ("A1")
        string slotType;          // Type of vehicle allowed ("Car" or "Motorcycle")
        bool isOccupied;          // Tracks if the slot currently has a parked vehicle
        bool isUnderMaintenance;  // Tracks if the slot is locked by administration
        Vehicle *vehicle;         // Aggregation: pointer to the parked vehicle (does not own)

    public:
        ParkingSlot(string id, string type); 
        ~ParkingSlot();

        // --- Mutator Functions ---
        void setSlotID(string id);
        void setSlotType(string type);
        void setIsOccupied(bool occupied);
        void setMaintenance(bool status);
        void setVehicle(Vehicle *v);

        // --- Accessor Functions---
        string getSlotID() const;
        string getSlotType() const;
        bool getIsOccupied() const;
        bool getIsUnderMaintenance() const;
        const Vehicle* getVehicle() const;

        // --- Utility Methods---
        void assignVehicle(Vehicle *v);  // Assigns a vehicle pointer to this slot and marks it occupied
        void clearSlot();                // Removes the vehicle reference without destroying the vehicle object

        friend ostream& operator<<(ostream &out, const ParkingSlot& obj); // Operator overload of output operator for matrix display
};

#endif