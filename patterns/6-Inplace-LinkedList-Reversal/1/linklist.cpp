// System headers

// Local includes
#include "linklist.h"

// Using declarations

// Statics, typedefs, globals

LLNode*
LinkedList::reverseInPlace(LLNode* head) {
    // Base case empty/single node list
    if (nullptr == head || nullptr == head->next()) {
        return head;
    }

    // Previously processed node
    LLNode* prevNode = nullptr;
    // Node currently being processed
    LLNode* currNode = head;
    // Iterate over the list sequentially element by element reversing the
    // current node at each iteration
    while (currNode) {
        // Store next node to be processed
        LLNode* nextNode = currNode->next();
        // Reverse list at current node
        currNode->setNext(prevNode);
        // Update previous node processed and next node to be processed
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}
