#include "RollbackManager.h"

// Abdullah: Constructor initializes the stack
RollbackManager::RollbackManager() { 
    top = nullptr; 
}

// Abdullah: Push a slot pointer onto the stack for later undo
void RollbackManager::push(ParkingSlot* slot) {
    if (slot == nullptr) return;

    RollbackNode* newNode = new RollbackNode;
    newNode->slot = slot;
    newNode->next = top;
    top = newNode;
}

// Abdullah: Pop and undo the last k actions
// Note: Printing is removed to comply with "only use RollbackManager.h" restriction
void RollbackManager::pop(int k) {
    for (int i = 0; i < k; i++) {
        if (top == nullptr) break;

        RollbackNode* temp = top;
        
        // Safety check before accessing slot pointer
        if (temp->slot != nullptr) {
            // Undo the allocation by setting status back to false
            temp->slot->isOccupied = false;
        }

        top = top->next;
        delete temp; // Manual memory management (No STL)
    }
}
