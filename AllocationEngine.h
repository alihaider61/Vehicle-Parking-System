#ifndef ALLOCATIONENGINE_H
#define ALLOCATIONENGINE_H

// Forward declaration: Tells the compiler Zone exists without loading the whole file yet
class Zone; 
class ParkingSlot; 

class AllocationEngine {
public:
    // Ali: Returns a pointer to a free slot, handles redirection
    ParkingSlot* allocate(Zone* zones, int zoneCount, int preferredZoneID);
};

#endif