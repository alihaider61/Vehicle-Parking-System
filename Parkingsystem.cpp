#include "ParkingSystem.h"

// Initialize system with dynamic array of Zones
ParkingSystem::ParkingSystem(int count) {
    zoneCount = count;
    zones = new Zone[zoneCount];
    for(int i = 0; i < zoneCount; i++) {
        zones[i].zoneID = i + 1;
    }
}

// Manual memory cleanup (No STL)
ParkingSystem::~ParkingSystem() {
    delete[] zones;
}

// Manual character array comparison (No <string> library)
bool ParkingSystem::isMatch(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}

// Logic for finding space and saving to rollback stack
void ParkingSystem::processRequest(ParkingRequest& req) {
    ParkingSlot* slot = engine.allocate(zones, zoneCount, req.preferredZone);
    if(slot != nullptr) {
        slot->isOccupied = true;
        rollback.push(slot); // Save action for potential Undo/Rollback
    }
}

// Calculation logic for receipts
void ParkingSystem::generateReceipt(const char* id, int hours, const char* type, const char* deal) {
    // Rates: 20 for Bike, 100 for others
    double rate = 100.0; 
    if (isMatch(type, "Bike")) rate = 20.0; 

    double total = rate * hours;

    // Overtime Logic: 10% increase if more than 1 hour
    if (hours > 1) total += (total * 0.10); 

    // Deals Logic: 15% off for Weekly, 30% off for Monthly
    if (isMatch(deal, "Weekly")) total *= 0.85;      
    else if (isMatch(deal, "Monthly")) total *= 0.70; 

    // Note: Output (cout) must be handled in main.cpp to comply with header-only include
}

// Logic for scanning building occupancy
void ParkingSystem::showStatus() {
    for(int i = 0; i < zoneCount; i++) {
        int used = 0;
        for(int j = 0; j < zones[i].areaCount; j++) {
            for(int k = 0; k < zones[i].areas[j].slotCount; k++) {
                if(zones[i].areas[j].slots[k].isOccupied) used++;
            }
        }
        // Building status data is updated; display logic belongs in the GUI/main
    }
}