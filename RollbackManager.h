#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H

#include "ParkingSlot.h"

// Abdullah: Custom Node for the Rollback Stack
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
    void undoLast(int k);
};

#endif