#include "ParkingRequest.h"

// Abdullah: Default Constructor
// FIX: Using ParkingRequest:: to link variables like 'active' and 'vehicleID'
ParkingRequest::ParkingRequest() {
    vehicleID[0] = '\0';
    vehicleType[0] = '\0';
    dealType[0] = '\0';
    preferredZone = -1;
    active = false; 
}

// Abdullah: Parameterized Constructor
// FIX: Using ParkingRequest:: allows access to the header's member variables
ParkingRequest::ParkingRequest(const char* id, const char* type, int zone, const char* deal) {
    
    // Manual copy for vehicleID (Fixes errors where 'vehicle' was undefined)
    int i = 0;
    while (id[i] != '\0' && i < 19) {
        vehicleID[i] = id[i];
        i++;
    }
    vehicleID[i] = '\0';

    // Manual copy for vehicleType
    i = 0;
    while (type[i] != '\0' && i < 9) {
        vehicleType[i] = type[i];
        i++;
    }
    vehicleType[i] = '\0';

    // Assigning zone and status
    preferredZone = zone;
    active = true; 

    // Manual copy for dealType
    i = 0;
    while (deal[i] != '\0' && i < 14) {
        dealType[i] = deal[i];
        i++;
    }
    dealType[i] = '\0';
}
