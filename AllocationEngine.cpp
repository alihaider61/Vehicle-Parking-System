#include "AllocationEngine.h"
#include <iostream>

ParkingSlot* AllocationEngine::allocate(Zone* zones, int zoneCount, int preferredZoneID) {
    [cite_start]// 1. Try Preferred Zone first [cite: 56]
    for(int i=0; i<zoneCount; i++) {
        if(zones[i].zoneID == preferredZoneID) {
            for(int j=0; j<zones[i].areaCount; j++) {
                for(int k=0; k<zones[i].areas[j].slotCount; k++) {
                    if(!zones[i].areas[j].slots[k].isOccupied) {
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }

    // 2. Cross-Zone Allocation (Auto-Redirect)
    for(int i=0; i<zoneCount; i++) {
        // Skip the preferred one (already checked)
        if(zones[i].zoneID != preferredZoneID) {
            for(int j=0; j<zones[i].areaCount; j++) {
                for(int k=0; k<zones[i].areas[j].slotCount; k++) {
                    if(!zones[i].areas[j].slots[k].isOccupied) {
                        std::cout << ">> NOTICE: Preferred Zone Full. Redirecting to Building " << zones[i].zoneID << std::endl;
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }

    // 3. All Full
    std::cout << ">> ALERT: All zones are full! No parking available." << std::endl; //
    return nullptr;
}