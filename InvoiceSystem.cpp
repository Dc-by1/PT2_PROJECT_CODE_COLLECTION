#include "InvoiceSystem.hpp"
#include "TicketSystem.hpp"
#include "Vehicle.hpp"

#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

//Constructor that set the revenue to 0
InvoiceSystem::InvoiceSystem() {
	totalCarRevenue = 0.0;
	totalMotoRevenue = 0.0;
}

//Destructor
InvoiceSystem::~InvoiceSystem() {}

//Accessor functions
double InvoiceSystem::getTotalCarRevenue() const {
	return totalCarRevenue;
}

double InvoiceSystem::getTotalMotoRevenue() const {
	return totalMotoRevenue;
}

//Mutator functions
void InvoiceSystem::setTotalCarRevenue(double fee) {
	totalCarRevenue = fee;
}

void InvoiceSystem::setTotalMotoRevenue(double fee) {
	totalMotoRevenue = fee;
}

//Used to add the revenue cumulatively instead of we need to calculate manually then assign back using mutators
void InvoiceSystem::addRevenue(Vehicle* v, double fee) {
	//determine which revenue need to be updated
	if (v->getType()=="Car")
		totalCarRevenue += fee;
	else if (v->getType()=="Motorcycle")
		totalMotoRevenue += fee;
	else {  //when the vehicle type is not valid
		cout << "Error occur, invalid vehicle type.\n";
		exit (1);
	}
}

//print the invoice for customer review
void InvoiceSystem::generateInvoice(TicketSystem* t, double fee, string exitTime) const {
	string fileName = "Invoice_" + t->getTicketID() + ".txt";	//generate invoice (.txt) file name based on ticket ID
	ofstream out(fileName);
	
	//output appropriate information on the invoice
	out << left << setprecision(2) << fixed;
	out << "=========================================" << endl
		<< setw(12) << "" << "PARKING INVOICE" << endl
		<< "=========================================" << endl
		<< setw(15) << "Ticket ID" << " : " << t->getTicketID() << endl
		<< setw(15) << "Plate No." << " : " << t->getPlate() << endl
		<< setw(15) << "Vehicle Type" << " : " << t->getVehicleType() << endl
		<< setw(15) << "Driver Status" << " : " << t->getDriverStatus() << endl
		<< setw(15) << "Slot ID" << " : " << t->getSlotID() << endl
		<< setw(15) << "Entry Time" << " : " << t->getEntryTime() << endl
		<< setw(15) << "Exit Time" << " : " << exitTime << endl
		<< setw(15) << "Total Fee" << " : RM " << fee << endl
		<< "=========================================" << endl;
	cout << "(Invoice generated: " << fileName << ")" << endl;
	out.close();
}

//append the daily audit log file for the vehicle entry and exit
void InvoiceSystem::appendAuditRecord(string logDetails) const {  //logDetails is a formatted string for log
	fstream out("Daily_Audit_Log.txt", ios::app);

    out << logDetails << endl;
    out.close();
}

//display on screen the daily financial report and system audit log
void InvoiceSystem::printRevenueReport() const {
	cout << left << setprecision(2) << fixed;
	cout << "=========================================" << endl
		 << setw(9) << "" << "DAILY FINANCIAL REPORT" << endl
		 << "=========================================" << endl
		 << setw(25) << "Total Car Revenue" << " : RM " << totalCarRevenue << endl
		 << setw(25) << "Total Motorcycle Revenue" << " : RM " << totalMotoRevenue << endl
		 << "-----------------------------------------" << endl
		 << setw(25) << "GRAND TOTAL" << " : RM " << totalCarRevenue + totalMotoRevenue << endl;
	
	string log;
	
		cout << "=========================================" << endl
		  	 << setw(12) << "" << "SYSTEM AUDIT LOG" << endl
			 << "=========================================" << endl;
	
	//repeated read and output the daily audit log
	ifstream in("Daily_Audit_Log.txt");
	if (!in)   //if the file doesn't exist
		cout << "Empty Audit Log Record!\n";
	else {
		while (getline(in, log))
			cout << log << endl;
			
		cout << "=========================================" << endl;
		in.close();
	}
}