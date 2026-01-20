#ifndef ZONE_H
#define ZONE_H
#include "ParkingArea.h"

class Zone {
public:
    int zoneID;
    ParkingArea* areas; // Array of floors/areas
    int areaCount;

    Zone();
    ~Zone();
};

#endif