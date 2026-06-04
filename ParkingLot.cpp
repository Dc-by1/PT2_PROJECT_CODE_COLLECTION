# include "ParkingLot.hpp"
# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

// Constructor: Generates flat slot rows, assigning row C for Motorcycles, the rest for Car
ParkingLot::ParkingLot(int r, int c):rows(r), cols(c){
    string type;
    for(int i=0; i< rows; i++){
        if(i == rows-1)
            type = "Motorcycle";  // If it is the last row, make it a Motorcycle row
        else
            type = "Car";

        for(int j=1; j<=cols; j++){
            string id ="";
            id += (char)('A'+i); //Example: id = A
            id += to_string(j);  //Then, id = A1
            slots.push_back(ParkingSlot(id, type)); // Save the slot into our list
        }
    }
}
ParkingLot::~ParkingLot(){}

// Setter to change the number of columns
void ParkingLot::setRows(int r){
    rows = r;
}
// Setter to change the number of columns
void ParkingLot::setCols(int c){
    cols = c;
}
// Setter to replace the whole slots list
void ParkingLot::setSlots(const vector<ParkingSlot> &s){
    slots = s;
}
// Setter to replace the whole tickets list
void ParkingLot::setTickets(const vector<TicketSystem> &t){
    tickets = t;
}
// Getter to see how many rows we have
int ParkingLot::getRows() const{
    return rows;
}
// Getter to see how many columns we have
int ParkingLot::getCols() const{
    return cols;
}
// Getter to read our list of slots
const vector<ParkingSlot>& ParkingLot::getSlots() const{
    return slots;
}
// Getter to read our list of tickets
const vector<TicketSystem>& ParkingLot::getTickets() const{
    return tickets;
}

// Pre-load 3 vehicles into the parking lot so we have some data to test with
void ParkingLot::initializeMockData(){                    
    Vehicle* v1 = new Vehicle("JDT1111", "Car");
    assignToSlot("A1", v1);
    TicketSystem t1;  // Ticket born inside the lot
    t1.generateTicket(v1, "A1", "08:00", "Standard"); 
    addTicket(t1);

    Vehicle* v2 = new Vehicle("BGP2222", "Motorcycle");
    assignToSlot("C1", v2);
    TicketSystem t2;
    t2.generateTicket(v2, "C1", "08:05", "Standard");
    addTicket(t2);

    Vehicle* v3 = new Vehicle("VIP3333", "Car");
    assignToSlot("B1", v3);
    TicketSystem t3;
    t3.generateTicket(v3, "B1", "08:10", "VIP");
    addTicket(t3);
}
// Print the parking lot grid layout nicely 
void ParkingLot::displayMatrix() const{
    cout<<"     >> PARKING LOT MATRIX <<"<<endl;
    cout<<"   ";
    for(int j=1; j<=cols; j++){
        cout<<"   "<<j<<"  ";          // display column number 1  2  3  4  5
    }
    cout<<endl;

    cout<<"  ";
    for(int j=0; j< cols; j++){
        cout<<"------";                // display the top border line
    }
    cout<<"-"<<endl;

    for(int i=0; i<rows; i++){
        char rowLabel = char('A'+i); // display row label A B C
        cout<<rowLabel<<" | ";      // display left border
        for(int j=0; j < cols; j++){
            cout<<slots[i*cols+j]<<" "; // Uses the overloaded operator<< from ParkingSlot to print [ C ] or [ M ]
        }
        
        cout<<"|"<<endl; //right border
    }

    cout<<"  ";
    for(int j=0; j<cols; j++){
        cout<<"------";              // display bottom border line
    }
    
    cout<<"-"<<endl;
    cout<<"Legend: [ C ] Car | [ M ] Motorcycle | [ X ] Maintenance | Row C = Motorcycle Slots"<<endl;
}
// Print the grid map but add a '*' next to the highlighted slot to show where a car is
void ParkingLot::displayMatrixHighlight(string highlightSlot) const{
    cout<<"     >> PARKING LOT MATRIX <<"<<endl;
    cout<<"  ";
    for(int j=1; j<=cols; j++){
        cout<<"   "<<j<<"  ";          // display column number 1  2  3  4  5
    }
    cout<<endl;

    cout<<"  ";
    for(int j=0; j<cols; j++){
        cout<<"------";                // display top border line
    }
    cout<<"-"<<endl;

    for(int i=0; i<rows; i++){
        char rowLabel = char('A'+i); // display row label A B C
        cout<<rowLabel<<" | ";      // display left border
        for(int j=0; j < cols; j++){
            cout<<slots[i*cols+j];
            if(slots[i*cols+j].getSlotID()== highlightSlot){
                cout<<"*";  // Add a star next to the driver's slot
            }
            else{
                cout<<" ";
            }
        }
        cout<<"|"<<endl; //right border
    }

    cout<<"  ";
    for(int j=0; j<cols; j++){
        cout<<"------";              // display bottom border
    }

    cout<<"-"<<endl;
    cout << "*(Your vehicle is located at slot " << highlightSlot << ")*" << endl;


}
// Find a slot by its ID and lock or unlock it for maintenance
void ParkingLot::setMaintenanceStatus(string slotID, bool status){
    for (size_t i = 0; i < slots.size(); i++) {
        if (slots[i].getSlotID() == slotID) {
            slots[i].setMaintenance(status);
            return; // Exit once found — do not fall through to error message
        }
    }

    cout<<"[ERROR] Slot " << slotID << " not found."<<endl;
}
// Find a specific slot by ID and put a vehicle pointer inside it
void ParkingLot::assignToSlot(string slotID, Vehicle* v){
    for (size_t i = 0; i < slots.size(); i++) {
        if (slots[i].getSlotID() == slotID) {
            slots[i].assignVehicle(v);
        }
    }
}
// Find the first empty, working slot that matches the vehicle type (Car or Motorcycle)
string ParkingLot::assignSlot(Vehicle *v, string entryTime, string driverStatus){
    if (v == nullptr) 
        return "";
    
    string required = v->getSlotRequirement(); // Get if it is a "Car" or "Motorcycle"
    for (size_t i = 0; i < slots.size(); i++) {
        // If the slot is empty, NOT under maintenance, and matches the vehicle type, take it
        if (!slots[i].getIsOccupied() && !slots[i].getIsUnderMaintenance() && slots[i].getSlotType() == required) {
            slots[i].assignVehicle(v);
            string currentSlotID = slots[i].getSlotID();
            TicketSystem newTicket;
            newTicket.generateTicket(v, currentSlotID, entryTime, driverStatus);
            addTicket(newTicket);
            cout << "[SYSTEM] Automatically generated Ticket: " << newTicket.getTicketID() << " for slot " << currentSlotID << endl;
            return currentSlotID; // Return the slot ID like "A2"
        }
    }
    return ""; // Return empty string if parking lot is completely full
}
// Free a slot by its ID when a vehicle leaves the parking lot
void ParkingLot::freeSlot(string slotID){
    for (size_t i = 0; i < slots.size(); i++) {
        if (slots[i].getSlotID() == slotID) {
            slots[i].clearSlot(); // Disconnect the vehicle from this slot
        }
    }
}

// Check if a plate number is already parked inside the lot to avoid double entry
bool ParkingLot::checkDuplicatePlate(string plate) const{
    Vehicle tempVehicle(plate, "Temp"); 
    string formattedPlate = tempVehicle.getPlate();  //create a temporary constructor to format the plate number
    for (size_t i = 0; i < slots.size(); i++) {
        if (slots[i].getIsOccupied() && slots[i].getVehicle() != nullptr) {
            if (slots[i].getVehicle()->getPlate() == formattedPlate) {
                return true; // Found a duplicate
            }
        }
    }
    return false; // No duplicate found
}
// Search for a vehicle by its plate number and print which slot it is in
void ParkingLot::searchVehicle(string plateNum) const{
    Vehicle tempVehicle(plateNum, "Temp"); 
    string formattedPlate = tempVehicle.getPlate(); 
    for (size_t i = 0; i < slots.size(); i++) {
        if (slots[i].getIsOccupied() && slots[i].getVehicle() != nullptr) {
            if (slots[i].getVehicle()->getPlate() == formattedPlate) {
                cout << "[FOUND] Plate " << formattedPlate
                     << " is in Slot " << slots[i].getSlotID() <<endl;
                     return;
            }
        }
    }
    cout << "[NOT FOUND] Plate " << formattedPlate << " is not currently parked." << endl;
}

// Add a new ticket object into our ticket tracking list
void ParkingLot::addTicket(TicketSystem t){
    tickets.push_back(t);
}
// Loop through our list to find and return a ticket pointer by its ID string
const TicketSystem* ParkingLot::findTicket(string ticketID) const{
    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets[i].getTicketID() == ticketID) {
            return &tickets[i]; // Return the address of the ticket
        }
    }
    return nullptr; // Return nullptr if ticket ID does not exist
}
