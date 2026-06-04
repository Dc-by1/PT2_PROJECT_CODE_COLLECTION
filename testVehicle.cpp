#include <iostream>
#include "Vehicle.hpp"

using namespace std;

int main() {
    cout << "Vehicle class testing" << endl;

    //Test Car Logic
    cout << "\nCreating a Car" << endl;
    Vehicle Car("abc 1234", "Car");
    
    cout << "Plate: " << Car.getPlate() << " | Type: " << Car.getType() << endl;
    cout << "Base Rate: RM " << Car.getBaseRate() << endl;
    cout << "Slot Type: " << Car.getSlotRequirement() << endl;
    
    //Test Motorcycle Logic
    cout << "\nCreating a Motorcycle" << endl;
    Vehicle Motor("abc 8888", "Motorcycle");
    
    cout << "Plate: " << Motor.getPlate() << " | Type: " << Motor.getType() << endl;
    cout << "Base Rate: RM " << Motor.getBaseRate() << endl;
    cout << "Slot Type: " << Motor.getSlotRequirement() << endl;

}