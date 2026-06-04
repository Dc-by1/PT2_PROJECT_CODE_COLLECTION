#include "TicketSystem.hpp"
#include "Vehicle.hpp"

#include <string>
using namespace std;

#ifndef INVOICESYSTEM_HPP
#define INVOICESYSTEM_HPP

class InvoiceSystem {
	private: 
		//private data members to store cumulative revenue for both car and motorcycle
		double totalCarRevenue;
		double totalMotoRevenue;
	public:
		//Constructor
		InvoiceSystem();
		
		//Destructor
		~InvoiceSystem();
		
		//Accessors
		double getTotalCarRevenue() const;
		double getTotalMotoRevenue() const;
		
		//Mutators
		void setTotalCarRevenue(double);
		void setTotalMotoRevenue(double);
		
		//Add the revenue cumulatively
		void addRevenue(Vehicle*, double);
		
		//print a .txt file to simulate the printing process of physical invoice
		void generateInvoice(TicketSystem*, double, string) const;
		
		//append the audit log record to the .txt file
		void appendAuditRecord(string) const;
		
		//display on screen the daily financial report (revenue) and audit log report from the .txt file
		void printRevenueReport() const;
};

#endif