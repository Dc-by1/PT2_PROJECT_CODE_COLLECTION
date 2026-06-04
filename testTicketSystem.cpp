#include "TicketSystem.hpp"
#include "Vehicle.hpp"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	cout << "=========================================" << endl;
    cout << "     TESTING TICKET SYSTEM MODULE        " << endl;
    cout << "=========================================" << endl;
    
    //creat the needed object
    TicketSystem ticket;
    Vehicle car("P12345", "Car");
    
    //check the initial status of the ticket after it was created
	cout << left;
	cout << "The initial value given by default constructor:\n"
    	 << setw(16) << "ticketID" << " : " << ticket.getTicketID() << endl
    	 << setw(16) << "plateNumber" << " : " << ticket.getPlate() << endl
		 << setw(16) << "vehicleType" << " : " << ticket.getVehicleType() << endl
    	 << setw(16) << "slotID" << " : " << ticket.getSlotID() << endl
		 << setw(16) << "manualEntryTime" << " : " << ticket.getEntryTime() << endl
    	 << setw(16) << "driverStatus" << " : " << ticket.getDriverStatus() << endl
    	 << setw(16) << "isActive" << " : " << (ticket.getIsActive()? "True": "False") << endl; 
    
    cout << endl << endl;
    
    //assign values using mutator functions 
    cout << "Assign the value using mutator:   (Manually generate a ticketID for an active ticket)\n";
    ticket.setTicketID("T0123");
	ticket.setPlate("P7788");
	ticket.setVehicleType("Motorcycle");
	ticket.setSlotID("L30");
	ticket.setEntryTime("12:30");
	ticket.setDriverStatus("OKU");
	ticket.setIsActive(true);
	
	//display ticket details
	cout << setw(16) << "ticketID" << " : " << ticket.getTicketID() << endl
    	 << setw(16) << "plateNumber" << " : " << ticket.getPlate() << endl
		 << setw(16) << "vehicleType" << " : " << ticket.getVehicleType() << endl
    	 << setw(16) << "slotID" << " : " << ticket.getSlotID() << endl
		 << setw(16) << "manualEntryTime" << " : " << ticket.getEntryTime() << endl
    	 << setw(16) << "driverStatus" << " : " << ticket.getDriverStatus() << endl
    	 << setw(16) << "isActive" << " : " << (ticket.getIsActive()? "True": "False") << endl; 
    	 
    cout << endl << endl;	 
	
	//use generateTicket() method to generate an activated ticket 
	cout << "Assign the value using generateTicket() method:   (Automatically generate a ticketID for an active ticket)\n";
		
	ticket.generateTicket(&car, "H12", "06:30", "VIP");
	
	//display ticket details
	cout << setw(16) << "ticketID" << " : " << ticket.getTicketID() << endl
	 << setw(16) << "plateNumber" << " : " << ticket.getPlate() << endl
	 << setw(16) << "vehicleType" << " : " << ticket.getVehicleType() << endl
	 << setw(16) << "slotID" << " : " << ticket.getSlotID() << endl
	 << setw(16) << "manualEntryTime" << " : " << ticket.getEntryTime() << endl
	 << setw(16) << "driverStatus" << " : " << ticket.getDriverStatus() << endl
	 << setw(16) << "isActive" << " : " << (ticket.getIsActive()? "True": "False") << endl; 
    	 
    cout << endl << endl;
    
    //use calculateDuration() method to calculate the parking duration in minutes
    cout << "Calculate parking duration using calculateDuration() method:\n"
    	 << "The duration of parking until 08:00 is " << ticket.calculateDuration("08:00") << " minutes" << endl;
    	 
   	cout << endl << endl;
	
	//use printTicket() method to display ticket details 
    cout << "Print the ticket details using printTicket() method:\n";
    ticket.printTicket();
    
	cout << endl << endl;
    
    cout << "\n=========================================" << endl;
    cout << "  TICKET SYSTEM MODULE TESTS COMPLETED   " << endl;
    cout << "=========================================" << endl;

    return 0;
}