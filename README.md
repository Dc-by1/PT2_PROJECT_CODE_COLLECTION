# PT2_PROJECT_CODE_COLLECTION

for testUser.cpp
->
g++ testUser.cpp user.cpp InvoiceSystem.cpp PricingCalculator.cpp TicketSystem.cpp Vehicle.cpp ParkingLot.cpp ParkingSlot.cpp -o testUser.exe

for testParkingLot.cpp-> g++ testParkingLot.cpp ParkingLot.cpp ParkingSlot.cpp TicketSystem.cpp Vehicle.cpp -o testParkingLot.exe

for testParkingSlot-> g++ testParkingSlot.cpp ParkingSlot.cpp Vehicle.cpp -o testParkingSlot.exe

for testVehicle -> g++ Vehicle.cpp testVehicle.cpp -o testVehicle.exe

for testPricingCalculator.cpp -> g++ testPricingCalculator.cpp PricingCalculator.cpp Vehicle.cpp -o testPricingCalculator.exe

for testTicketSystem.cpp -> g++ testTicketSystem.cpp TicketSystem.cpp Vehicle.cpp -o testTicketSystem.exe

for testInvoiceSystem.cpp -> g++ testInvoiceSystem.cpp InvoiceSystem.cpp TicketSystem.cpp Vehicle.cpp -o testInvoiceSystem.exe
