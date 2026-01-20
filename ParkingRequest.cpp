#include "ParkingRequest.h"

// Abdullah: Constructor for ParkingRequest
ParkingRequest::ParkingRequest(const char* id, const char* type, int zone, const char* deal) {
    // ERROR 1 FIX: 'vehicle' must be lowercase to match the object name in the .h file
    vehicle.setData(id, type); 

    // ERROR 2 FIX: Ensure preferredZone is assigned correctly
    preferredZone = zone;
    
    // ERROR 3 FIX: status must be PENDING (ensure RequestState::PENDING is defined in .h)
    status = PENDING;

    // Abdullah: Manual copy for the deal string (No <string> library)
    int i = 0;
    while (deal[i] != '\0') { 
        dealType[i] = deal[i]; 
        i++; 
    }
    dealType[i] = '\0'; // Always null-terminate char arrays
}