#include "Vehicle.hpp"

#include <string>
using namespace std;

#ifndef TICKETSYSTEM_HPP
#define TICKETSYSTEM_HPP

class TicketSystem {   //each object of the class represent single ticket
	private: 
		//private data members inside a single ticket					 
		string ticketID;
		string plateNumber;
		string vehicleType;
		string slotID;
		string manualEntryTime;
		string driverStatus;
		bool isActive;
	public:
		//Constructor
		TicketSystem();			
		
		//Destructor
		~TicketSystem();		
		
		//Accessors
		string getTicketID() const;		
		string getPlate() const;
		string getVehicleType() const;
		string getSlotID() const;
		string getEntryTime() const;
		string getDriverStatus() const;
		bool getIsActive() const;
		
		//Mutators
		void setTicketID(string);		
		void setPlate(string);
		void setVehicleType(string);
		void setSlotID(string);
		void setEntryTime(string);
		void setDriverStatus(string);
		void setIsActive(bool);  //Used to determine whether the ticket are still valid 
		
		//Combination of mutator functions to generate an active ticket and generate ticketID automatically based on ticketCounter
		void generateTicket(Vehicle*, string, string, string = "Standard"); 
		
		//Use the data member manualEntryTime and timeOut provided via parameter to calculate and return the parking duration in minutes
		int calculateDuration(string) const;
		
		//Combination of accessor function that display the details in the ticket
		void printTicket() const;
};

#endif