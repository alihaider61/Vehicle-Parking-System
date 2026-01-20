#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H

#include "ParkingSlot.h"

struct RollbackNode {
    ParkingSlot* slotPtr;
    RollbackNode* next;
};

class RollbackManager {
private:
    RollbackNode* top;
public:
    RollbackManager();
    void recordAction(ParkingSlot* slot);
    void undoLast(int k); // Release last k slots
};

#endif