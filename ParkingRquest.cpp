#include "ParkingRequest.h"

ParkingRequest::ParkingRequest(const char* id, const char* type, int zone, const char* deal) {
    vehicle.setData(id, type);
    preferredZone = zone;
    status = PENDING;

    int i = 0;
    while (deal[i] != '\0') { dealType[i] = deal[i]; i++; }
    dealType[i] = '\0';
}