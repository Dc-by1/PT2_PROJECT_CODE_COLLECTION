#include "TicketSystem.hpp"
#include "Vehicle.hpp"

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//A counter that allows the system to generate different ticketID automatically
int ticketCounter = 1001; 	

//Constuctor that generate empty ticket without any information and need to be "filled in" and activated;
TicketSystem::TicketSystem() {
	ticketID = "";
	plateNumber = "";
	vehicleType = "";
	slotID = "";
	manualEntryTime = "" ;
	driverStatus = "Standard" ;
	isActive = false;
}

//Destructor
TicketSystem::~TicketSystem() {}

//Accessor functions that allow us to access the private data members outside the class
string TicketSystem::getTicketID() const {
	return ticketID;
}

string TicketSystem::getPlate() const {
	return plateNumber;
}

string TicketSystem::getVehicleType() const {
	return vehicleType;
	
}
string TicketSystem::getSlotID() const {
	return slotID;
}

string TicketSystem::getEntryTime() const {
	return manualEntryTime;
}

string TicketSystem::getDriverStatus() const {
	return driverStatus;
}

bool TicketSystem::getIsActive() const {
	return isActive;
}

//Mutator functions that allow us to assign data into the private data members outside the class
void TicketSystem::setTicketID(string ticket) {
	ticketID = ticket;
}

void TicketSystem::setPlate(string plate) {
	plateNumber = plate;
}

void TicketSystem::setVehicleType(string type) {
	vehicleType = type;
}

void TicketSystem::setSlotID(string slot) {
	slotID = slot;
}

void TicketSystem::setEntryTime(string timeIn) {
	manualEntryTime = timeIn;
}

void TicketSystem::setDriverStatus(string status) {
	driverStatus = status;
}

void TicketSystem::setIsActive(bool active) {
	isActive = active;
}

//Act as a combination of mutator functions and use the ticketCounter to generate ticketID automatically instead of enter manually
void TicketSystem::generateTicket(Vehicle* v, string slot, string timeIn, string status) {
	ticketID = "T" + to_string(ticketCounter++);	//generate ticketID based on ticketCounter
    plateNumber = v->getPlate();
    vehicleType = v->getType(); 
    slotID = slot;
    manualEntryTime = timeIn;
    driverStatus = status;
    isActive = true;	//indicate the ticket is now activated
}

//Convert the time in and out from HH:MM format to integer value (minutes) and calculate the parking duration
int TicketSystem::calculateDuration(string timeOut) const {
	int hIn, mIn, hOut, mOut;	//h for hour and m for minute
	
	//separate hours and minutes and convert into integer
	hIn = stoi(manualEntryTime.substr(0, 2));
    mIn = stoi(manualEntryTime.substr(3, 2));
    hOut = stoi(timeOut.substr(0, 2));
    mOut = stoi(timeOut.substr(3, 2));
    
    //detect the invalid time entered
    if (hIn  < 0 || hIn  > 23 || mIn  < 0 || mIn  > 59 || hOut < 0 || hOut > 23 || mOut < 0 || mOut > 59)
	    return -1;
	
	//calculate the time in and out in minutes
	int totalIn = hIn * 60 + mIn;
	int totalOut = hOut * 60 + mOut;	
	
	//if time out < time in meaning that the vehicle exit at second day
	if (totalOut < totalIn) {
            totalOut += 24 * 60;
    }
    
    return totalOut - totalIn;		//return duration in minutes
}

//Act as a combination of accessor functions to display several details in the ticket
void TicketSystem::printTicket() const {
	cout << "=========================================" << endl
    	 << setw(13) << "" << "PARKING TICKET" << endl
    	 << "=========================================" << endl
    	 << left << setw(14) << "Ticket ID" << ": " << ticketID << endl
    	 << left << setw(14) << "Plate No." << ": " << plateNumber << endl
   		 << left << setw(14) << "Vehicle Type" << ": " << vehicleType << endl
    	 << left << setw(14) << "Slot ID" << ": " << slotID << endl
    	 << left << setw(14) << "Entry Time" << ": " << manualEntryTime << endl
    	 << left << setw(14) << "Driver Status" << ": " << driverStatus << endl
    	 << left << setw(14) << "Active" << ": " << (isActive? "True": "False") << endl
    	 << "=========================================" << endl
    	 << "Please keep your Ticket ID for exit verification." << endl;
}