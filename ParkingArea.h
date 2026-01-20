#ifndef PARKINGAREA_H
#define PARKINGAREA_H
#include "ParkingSlot.h"

class ParkingArea {
public:
    ParkingSlot* slots; // Custom dynamic array
    int slotCount;

    ParkingArea();
    ~ParkingArea();
};

#endif