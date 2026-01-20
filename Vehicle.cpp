#include "Vehicle.h"

Vehicle::Vehicle() {
    vehicleID[0] = '\0';
    vehicleType[0] = '\0';
}

void Vehicle::setData(const char* id, const char* type) {
    int i = 0;
    while (id[i] != '\0') { vehicleID[i] = id[i]; i++; }
    vehicleID[i] = '\0';
    
    i = 0;
    while (type[i] != '\0') { vehicleType[i] = type[i]; i++; }
    vehicleType[i] = '\0';
}