#include "AllocationEngine.h"
#include <cstdio> // Abdullah and Ali: Use this instead of iostream

ParkingSlot* AllocationEngine::allocate(Zone* zones, int zoneCount, int preferredZoneID) {
    // 1. Try Preferred Zone first
    for(int i = 0; i < zoneCount; i++) {
        if(zones[i].zoneID == preferredZoneID) {
            for(int j = 0; j < zones[i].areaCount; j++) {
                for(int k = 0; k < zones[i].areas[j].slotCount; k++) {
                    if(!zones[i].areas[j].slots[k].isOccupied) {
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }

    // 2. Cross-Zone Allocation (Auto-Redirect)
    for(int i = 0; i < zoneCount; i++) {
        // Skip the preferred one (already checked)
        if(zones[i].zoneID != preferredZoneID) {
            for(int j = 0; j < zones[i].areaCount; j++) {
                for(int k = 0; k < zones[i].areas[j].slotCount; k++) {
                    if(!zones[i].areas[j].slots[k].isOccupied) {
                        // REPLACED std::cout with printf
                        printf(">> NOTICE: Preferred Zone Full. Redirecting to Building %d\n", zones[i].zoneID);
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }

    // 3. All Full
    // REPLACED std::cout with printf
    printf(">> ALERT: All zones are full! No parking available.\n");
    return nullptr;
}