#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H

#include "ParkingSlot.h"

// Abdullah: Node for custom stack
struct RollbackNode {
    ParkingSlot* slot;
    RollbackNode* next;
};

class RollbackManager {
private:
    RollbackNode* top;

public:
    RollbackManager();
    void push(ParkingSlot* slot);
    void pop(int k);
};

#endif