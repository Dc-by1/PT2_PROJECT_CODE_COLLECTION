#include "InvoiceSystem.hpp"
#include "TicketSystem.hpp"
#include "Vehicle.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "=========================================" << endl;
    cout << "     TESTING INVOICE SYSTEM MODULE       " << endl;
    cout << "=========================================" << endl;
	
	cout << setprecision(2) << fixed;
	
	//create the needed object
    InvoiceSystem system;
    
    Vehicle car("P12345", "Car");
    Vehicle moto("P67890", "Motorcycle");
    
    TicketSystem ticket1, ticket2;
    ticket1.generateTicket(&car, "H12", "06:30", "Standard");
    ticket2.generateTicket(&moto, "C12", "09:30", "VIP");
    
    //check the initial value of the revenue given by constructor
    cout << "The initial value given by default constructor:\n"
    	 << "totalCarRevenue \t: RM" << system.getTotalCarRevenue() << endl
    	 << "totalMotoRevenue\t: RM" << system.getTotalMotoRevenue() << endl; 
    	 
    cout << endl << endl;
    
    //assign values using mutator functions 
    cout << "Assign value using mutator:\n\n";
    system.setTotalCarRevenue(20.5);
    system.setTotalMotoRevenue(30.8);
    cout << "totalCarRevenue \t: RM" << system.getTotalCarRevenue() << endl
    	 << "totalMotoRevenue\t: RM" << system.getTotalMotoRevenue() << endl;
		
	cout << endl << endl;
	
	//add the revenue using addRevenue() method instead of calculate and pass to mutator manually
	cout << "Add revenue using addRevenue() method:\n\n";
	system.addRevenue(&car, 50);
	system.addRevenue(&moto, 20);
	cout << "totalCarRevenue \t: RM" << system.getTotalCarRevenue() << endl
    	 << "totalMotoRevenue\t: RM" << system.getTotalMotoRevenue() << endl;
		 
	cout << endl << endl;
	
	//generate the invoice in .txt file
	cout << "GenerateInvoice using generateInvoice() method:\n\n";
	system.generateInvoice(&ticket1, 50.5, "07:30"); 
	cout << "The Invoice generated in .txt file." << endl;

	cout << endl << endl;
	
	//append the audit log record by passing the logDetails in formatted string
	cout << "Append the audit log record using appendAuditRecord() method:\n\n";
	system.appendAuditRecord("[06:30] ENTRY - Car (P12345) entered H12 [Standard]");
	system.appendAuditRecord("[07:30] EXIT - Car (P12345) paid RM2.00 and left H12");
	system.appendAuditRecord("[09:30] ENTRY - Moto (P67890) entered C12 [VIP]");
	cout << "The audit log report (Daily_Audit_Log.txt) have been updated." << endl;
	
	cout << endl << endl;
	
	//print the audit log record andd daily financial report on screen
	cout << "Print the audit log record and daily financial report using printRevenueReport() method:\n\n";
	system.printRevenueReport();
	
	cout << endl << endl;
    
    cout << "\n=========================================" << endl;
    cout << "  INVOICE SYSTEM MODULE TESTS COMPLETED  " << endl;
    cout << "=========================================" << endl;

    return 0;
}