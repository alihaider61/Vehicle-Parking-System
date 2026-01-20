#include "ParkingArea.h"

ParkingArea::ParkingArea() {
    slotCount = 5; // Each floor has 5 slots for testing
    slots = new ParkingSlot[slotCount];
    for(int i=0; i<slotCount; i++) {
        slots[i].slotID = i + 1;
        slots[i].isOccupied = false;
    }
}

ParkingArea::~ParkingArea() {
    delete[] slots;
}