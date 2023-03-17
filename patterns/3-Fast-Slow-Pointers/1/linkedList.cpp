// System headers

// Local includes
#include "linkedList.h"

// Using declarations

// Statics, typedefs, globals

bool
LinkedList::hasCycle(LLNode* head) {
    // Base case (empty list/single node list)
    if (nullptr == head || nullptr == head->next()) {
        return false;
    }

    // Commence with 2 pointers at head of list. One of the pointers(fast)
    // moves at 2x the speed of other(slow pointer). Traverse the list with
    // pointers till the fast pointer reaches last node (no loop) or both
    // the fast and slow pointers ending up referring to each other
    // (indicating loop presence)
    LLNode *slowPtr = head;
    LLNode *fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next() != nullptr) {
        // Advance slowPtr one step
        slowPtr = slowPtr->next();
        // Advance fastPtr two steps
        fastPtr = fastPtr->next();
        fastPtr = fastPtr->next();

        if (slowPtr == fastPtr) {
            return true; // Cycle detected
        }
    }

    return false;
}

unsigned int
LinkedList::numNodesInCycle(LLNode* startNode) {
    unsigned int cnt = 0;
    LLNode* currNode = startNode;
    // Traverse once round the cycle keeping tack of node count
    // till starting node is reached
    do {
        ++cnt;
        currNode = currNode->next();
    } while (currNode != startNode);

    return cnt;
}

unsigned int
LinkedList::cycleLength(LLNode* head) {
    // Base case (empty list/single node list)
    if (nullptr == head || nullptr == head->next()) {
        return 0;
    }

    // Check for presence of a cycle and get a pointer
    // to a node within it using the slow/fast pointers
    LLNode* slowPtr = head;
    LLNode* fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next() != nullptr) {
        // Advance fastPtr 2 steps
        fastPtr = fastPtr->next();
        fastPtr = fastPtr->next();
        // Advance slowPtr 1 step
        slowPtr = slowPtr->next();
        if (slowPtr == fastPtr) {
            // Cycle present
            return numNodesInCycle(slowPtr);
        }
    }

    // No cycle present
    return 0;
}

