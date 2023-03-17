// System headers

// Local includes
#include "linkedList.h"

// Using declarations

// Statics, typedefs, globals

LLNode*
LinkedList::middleNode(LLNode* head) {
    // Base case (null or single node list)
    if ((nullptr == head) || (nullptr == head->next())) {
        return head;
    }

    // Have 2 pointers (fast and slow) initialized to the list head node.
    // Fast pointer moves at 2x the slow pointer speed in steps. Iterate
    // over the list using the two pointers. When fast pointer has reached
    // the list end, slow pointer would have traversed half the distance,
    // that is, it would be at the list middle node
    LLNode* fastPtr = head;
    LLNode* slowPtr = head;
    while (nullptr != fastPtr && nullptr != fastPtr->next()) {
        // Advance slowPtr one step
        slowPtr = slowPtr->next();
        // Advance fastPtr two steps
        fastPtr = fastPtr->next();
        fastPtr = fastPtr->next();
    }

    return slowPtr;
}
