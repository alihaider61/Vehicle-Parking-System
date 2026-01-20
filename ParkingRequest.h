#ifndef PARKINGREQUEST_H
#define PARKINGREQUEST_H

class ParkingRequest {
public:
    char vehicleID[20];
    char vehicleType[10]; // Bike, Car, Jeep
    char dealType[15];    // Weekly, Monthly
    int preferredZone;
    bool active;

    ParkingRequest();
    ParkingRequest(const char* id, const char* type, int zone, const char* deal);
};

#endif