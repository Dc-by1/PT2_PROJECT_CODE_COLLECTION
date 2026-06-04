#include "PricingCalculator.hpp"
#include "Vehicle.hpp"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	cout << "=========================================" << endl;
    cout << "   TESTING PRICING CALCULATOR MODULE     " << endl;
    cout << "=========================================" << endl;
    
    //create the needed object
	Vehicle car("P12345", "Car");
    Vehicle moto("P67890", "Motorcycle");
	PricingCalculator cal;
	
	//check the initial value of the dailyCap if no argument is passed to the constructor
	cout << setprecision(2) << fixed;
	cout << "The initial value given by default constructor:\n"
    	 << "dailyCap : RM" << cal.getDailyCap() << endl;
    	 
    cout << endl << endl;
    
    //assign value to dailyCap using mutator function
	cout << "Assign value using mutator:\n";
	cal.setDailyCap(10);
	cout << "dailyCap : RM" << cal.getDailyCap() << endl;
	
	cout << endl << endl;
	
	//use calculateFee() method to calculate fee for different duration, vehicle type, and driver status
	cout << "Calculate fee using calculateFee() method:\n";
	cout << "The fee for the car is : RM" << cal.calculateFee(600, &car, "Standard") << "    (The fee archive the maximum daily cap)" << endl;
	cout << "The fee for the moto is: RM" << cal.calculateFee(120, &moto, "VIP") << endl;
    
    cout << "\n=========================================" << endl;
    cout << "PRICING CALCULATOR MODULE TESTS COMPLETED" << endl;
    cout << "=========================================" << endl;
    
    return 0; 
}