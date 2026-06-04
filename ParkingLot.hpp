# ifndef PARKINGLOT_HPP
# define PARKINGLOT_HPP

# include "ParkingSlot.hpp"
# include "TicketSystem.hpp"

# include <vector>
# include <string>
using namespace std;

//Purpose: Manages a grid-based collection of ParkingSlots and tracks ticketing.
class ParkingLot{
    private:
        vector<ParkingSlot> slots;    // Composition: Destroys all slots automatically when lot dies
        int rows;                     // Total rows of parking lot
        int cols;                     // Total columns of parking lot
        vector<TicketSystem> tickets; // Composition: Internal system ticket record logs

    public:
        ParkingLot(int r=3, int c=5); // Constructor specifying default dimensions 3x5
        ~ParkingLot();

        // --- Mutator Functions---
        void setRows(int r);
        void setCols(int c);
        void setSlots(const vector<ParkingSlot> &s);
        void setTickets(const vector<TicketSystem> &t);

        // --- Accessor Functions---
        int getRows() const;
        int getCols() const;
        const vector<ParkingSlot>& getSlots() const;
        const vector<TicketSystem>& getTickets() const;

        // ---Utility Methods---
        void initializeMockData();  // Pre-loads sample vehicles into slots
        void displayMatrix() const;       // Display whole parking lot
        void displayMatrixHighlight(string highlightSlot) const; // Highlights a target vehicle slot inside the grid array
        void setMaintenanceStatus(string slotID, bool status); // Allows administrators to lock down specific slots for servicing
        void assignToSlot(string slotID, Vehicle* v); // Put a dynamic vehicle reference onto a known slot coordinate
        string assignSlot(Vehicle *v, string entryTime, string driverStatus); // Auto-allocates the first compliant, open slot matching the vehicle specifications
        void freeSlot(string slotID);  // Frees a target slot coordinate asset
        bool checkDuplicatePlate(string plate) const; // Scans the active rows to catch duplicate active plates early
        void searchVehicle(string plateNum) const; // Scans plate allocations and displays slot findings to console
        void addTicket(TicketSystem t); // Extends ticket vector track registers with external records
        const TicketSystem* findTicket(string ticketID) const; // Searches for matching tickets

};

#endif