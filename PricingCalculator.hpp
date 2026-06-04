#include "Vehicle.hpp"

#include <string>
using namespace std;

#ifndef PRICINGCALCULATOR_HPP
#define PRICINGCALCULATOR_HPP

class PricingCalculator {
	private: 
		//private data member to indicate the maximum of daily fee
		double dailyCap;
	public:
		//Constructor with default argument to assign dailyCap = 100 if no value is passed when object is created
		PricingCalculator(double = 100);
		
		//Destructor
		~PricingCalculator();
		
		//Accessor
		double getDailyCap() const;
		
		//Mutator
		void setDailyCap(double);
		
		//Calculate the fee need to be paid based on duration, vehicle type and driverStatus
		double calculateFee(int, Vehicle*, string) const;		
};

#endif