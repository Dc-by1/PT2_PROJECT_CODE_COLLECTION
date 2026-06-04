# include "ParkingSlot.hpp"
# include "Vehicle.hpp"
# include <iostream>
using namespace std;

int main(){

    cout<<"==============================================="<<endl;
    cout<<"           TESTING CLASS: PARKINGSLOT          "<<endl;
    cout<<"==============================================="<<endl<<endl;

    //Demostrate constructor initialization
    ParkingSlot slot("A1", "Motorcycle");
    cout<<"We create a slot with motorcycle type and ID A1"<<endl;
    cout<<"Initial Slot ID   : "<<slot.getSlotID() << endl;
    cout<<"Initial Slot Type : "<<slot.getSlotType()<<endl;
    cout<<"Initial Occupied  : "<< (slot.getIsOccupied() ? "Yes" : "No")<<endl<<endl;

    //Demonstrate Accessor and Mutator functions
    slot.setSlotID("B2");
    slot.setSlotType("Car");
    cout<<"After setters that set slot ID to B2 and slot type to Car"<<endl
        <<"Slot ID           : "<<slot.getSlotID()<<endl
        <<"Slot Type         : "<<slot.getSlotType()<<endl<<endl;


    //Demonstrate Aggregation relationship with independent Vehicle lifetime
    cout<<"Testing Aggregation with Vehicle class"<<endl;
    cout<<"Create a new vehicle (Car), with plate number JJS6606 "<<endl;
    Vehicle* myCar = new Vehicle("JJS6606", "Car");
    // Connect vehicle to slot
    slot.assignVehicle(myCar);

    cout<<slot.getSlotID()<<" Occupied Status : "<<(slot.getIsOccupied()? "Yes": "No")<<endl;  //We assume the slot type will match with vehicle type for this unit testing
    cout<<slot<<endl;

    //Clear slot and show that vehicle still exists independently
    cout<<"\nClear the slot of JJS6606"<<endl;
    slot.clearSlot();
    cout<<"Slot cleared. Occupied Status: "<<(slot.getIsOccupied()? "Yes": "No")<<endl;
    cout<<slot<<endl;

    cout<<"\nChecking vehicle after slot cleared."<<endl;
    cout<<"Plate: "<<myCar->getPlate()<<" still exists"<<endl;

    //Clean up dynamic memory for the independent vehicle object
    delete myCar;
    system("pause");
    return 0;

}

