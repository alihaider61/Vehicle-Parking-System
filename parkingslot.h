#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

struct ParkingSlot {
    int slotID;
    int zoneID;
    bool isOccupied; // 0 = Available, 1 = Occupied

    ParkingSlot() : slotID(0), zoneID(0), isOccupied(false) {}
};

#endif