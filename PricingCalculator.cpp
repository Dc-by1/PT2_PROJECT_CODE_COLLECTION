#include "PricingCalculator.hpp"
#include "Vehicle.hpp"

#include <string>
using namespace std;

//Constructor that assign the value into dailyCap with default argument double cap=100
PricingCalculator::PricingCalculator(double cap) {
	dailyCap = cap;
}

//Destructor
PricingCalculator::~PricingCalculator() {}

//Accessor
double PricingCalculator::getDailyCap() const {
	return dailyCap;
}

//Mutator
void PricingCalculator::setDailyCap(double cap) {
	dailyCap = cap;
}

//Calculate the fee need to be paid
double PricingCalculator::calculateFee(int durationMins, Vehicle* v, string driverStatus = "Standard") const {
	double fee;
	int chargedHour = durationMins/60;  //convert the duration to integer hour that will be charged
	
	//determine the discount based on the driverStatus either VIP (20%), OKU (50%) or Standard (0%)
	if (driverStatus=="VIP")  
		fee = chargedHour * v->getBaseRate() * 0.8;  //v->getBaseRate() to get different base rate for different vehicle type
	else if (driverStatus=="OKU")
		fee = chargedHour * v->getBaseRate() * 0.5;
	else
		fee = chargedHour * v->getBaseRate();
	
	//if the fee exceed the dailyCap, then we only pay for dailyCap amount
	if (fee>dailyCap)
		fee = dailyCap;
	
	return fee;
}