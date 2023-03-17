// System headers

// Local includes
#include "linkedList.h"

// Using declarations

// Statics, typedefs, globals

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

LLNode*
LinkedList::cycleStartNode(LLNode* head, unsigned int cycleLen) {
    // Have 2 pointers commencing traversal from start of list
    LLNode* ptr1 = head;
    LLNode* ptr2 = head;

    // Advance one of the pointers by cycle length nodes - ptr2
    while (cycleLen--) {
        ptr2 = ptr2->next();
    }

    // Move both the pointers one node at a time till they meet
    // Since ptr2 is cycleLen nodes ahead, it would have completed
    // one loop round the list cycle and come back to the node
    // which is the start of cycle. So both pointers meet at cycle start
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next();
        ptr2 = ptr2->next();
    }

    return ptr1;
}

LLNode*
LinkedList::cycleStartNode(LLNode* head) {
    // Base case (empty list/single node list)
    if (nullptr == head || nullptr == head->next()) {
        return nullptr;
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
            // Compute cycle length/number of nodes in cycle
            unsigned int cl = numNodesInCycle(slowPtr);
            // Find the cycle start node
            return cycleStartNode(head, cl);
        }
    }

    // No cycle present
    return nullptr;
}

