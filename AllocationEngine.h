#ifndef ALLOCATIONENGINE_H
#define ALLOCATIONENGINE_H
#include "Zone.h"

class AllocationEngine {
public:
    // Returns a pointer to a free slot, handles redirection
    ParkingSlot* allocate(Zone* zones, int zoneCount, int preferredZoneID);
};

#endif