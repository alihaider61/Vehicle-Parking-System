#include "AllocationEngine.h"
#include "Zone.h"
#include "ParkingArea.h"
#include "ParkingSlot.h"

ParkingSlot* AllocationEngine::allocate(
    Zone* zones,
    int zoneCount,
    int preferredZoneID
) {
    // 1. Try preferred zone first
    for (int i = 0; i < zoneCount; i++) {
        if (zones[i].zoneID == preferredZoneID) {
            for (int j = 0; j < zones[i].areaCount; j++) {
                for (int k = 0; k < zones[i].areas[j].slotCount; k++) {
                    if (!zones[i].areas[j].slots[k].isOccupied) {
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }

    // 2. Cross-zone allocation (auto redirect)
    for (int i = 0; i < zoneCount; i++) {
        if (zones[i].zoneID != preferredZoneID) {
            for (int j = 0; j < zones[i].areaCount; j++) {
                for (int k = 0; k < zones[i].areas[j].slotCount; k++) {
                    if (!zones[i].areas[j].slots[k].isOccupied) {
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }

    // 3. No parking available
    return nullptr;
}
