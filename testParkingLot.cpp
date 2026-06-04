# include "ParkingLot.hpp"
# include "TicketSystem.hpp"

# include <iostream>
# include <string>
using namespace std;

int main(){
    cout<<"========================================="<<endl;
    cout<<"        TESTING CLASS: PARKINGLOT        "<<endl;
    cout<<"========================================="<<endl<<endl;

    //Create a parking lot object with 3 rows and 5 columns
    cout<<"Instantiating ParkingLot"<<endl;
    ParkingLot myLot(3,5);

    // Since slots are fully owned by ParkingLot, they are automatically created here.
    cout << "Total slots created automatically inside the lot: " << myLot.getSlots().size() << endl;
    cout<<"Initial Map:"<<endl;
    myLot.displayMatrix();

    cout << "Ticket count before any vehicles park: " << myLot.getTickets().size() << endl;
    
    //Add 3 cars/motorcycles into the lot to test if it works
    cout<<"\n\nPre-loading 3 mock vehicles into parking lot"<<endl;
    myLot.initializeMockData();
    cout << "Ticket count after initializeMockData() (3 vehicles): "<< myLot.getTickets().size() << endl;
    cout << "(Tickets were created inside the lot, no external TicketSystem objects were made)" << endl;
    cout<<"\nCurrent Map:"<<endl;
    myLot.displayMatrix();

    //Test the auto-assign slot function for a new car
    cout << "\nParking a new car UTM1234" << endl;
    Vehicle *newCar = new Vehicle("UTM1234", "Car");
    string newCarSlot = myLot.assignSlot(newCar, "11:30", "Standard");
    cout << "Ticket count after new car entered: "<< myLot.getTickets().size() << endl;

    //Show the map again, but with a '*' marking where the new car is
    cout<<"\nGenerate highlighting map for newCar location tracing:"<<endl;
    myLot.displayMatrixHighlight(newCarSlot);

    cout<<"\nFinding ticket T1001"<<endl;
    // Test if we can find a ticket by its ID
    if (myLot.findTicket("T1001") != nullptr) {
        cout << "[SUCCESS] Ticket found inside ParkingLot container!" << endl;
    } else {
        cout << "[ERROR] Ticket not found!" <<endl;
    }

    cout<<"\n---Test for other utility methods---"<<endl;
    //Test the search function with messy input (lowercase and spaces)
    cout<<"Searching for vehicle jdt 1111 (lowercase with space):"<<endl;
    myLot.searchVehicle("jdt 1111");
    //Test if the system can detect a car that is already parked
    cout<<"If we try enter UTM1234 again"<<endl;
    cout<<"Is plate UTM1234 recognized as duplicate? : "<<(myLot.checkDuplicatePlate("Utm1234")? "Yes": "No")<<endl;

    //Test searching for a car that does not exist in the parking lot
    cout<<"Search for absent vehicle XYZ1234: "<<endl;
    myLot.searchVehicle("XYZ1234");

    // Highlight map showing new car location
    cout << "\nHighlight map for newCar at slot " << newCarSlot << ":" << endl;
    myLot.displayMatrixHighlight(newCarSlot);

    // Maintenance test
    cout << "\nSetting slot B2 under maintenance..." << endl;
    myLot.setMaintenanceStatus("B2", true);
    cout << "Map after maintenance set:" << endl;
    myLot.displayMatrix();

    // Free a slot test
    cout << "\nFreeing slot A1 (JDT1111 leaving)..." << endl;
    myLot.freeSlot("A1");
    cout << "Map after A1 is free:" << endl;
    myLot.displayMatrix();


    system("pause");
    return 0;
}