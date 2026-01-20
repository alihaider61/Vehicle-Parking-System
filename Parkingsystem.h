#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H
#include "Zone.h"
#include "AllocationEngine.h"
#include "RollbackManager.h"
#include "ParkingRequest.h"

class ParkingSystem {
private:
    Zone* zones;
    int zoneCount;
    AllocationEngine engine;
    RollbackManager rollback;

    // Helper to compare strings manually
    bool isMatch(const char* s1, const char* s2);

public:
    ParkingSystem(int count);
    ~ParkingSystem();

    void processRequest(ParkingRequest& req);
    void generateReceipt(const char* id, int hours, const char* type, const char* deal);
    void showStatus();
};

#endif