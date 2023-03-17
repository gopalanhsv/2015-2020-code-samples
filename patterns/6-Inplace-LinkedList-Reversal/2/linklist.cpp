// System headers
#include <stdexcept>

// Local includes
#include "linklist.h"

// Using declarations
using std::domain_error;

// Statics, typedefs, globals

LLNode*
LinkedList::reverseSubList(LLNode* head, int p, int q) {
    if (p > q || p < 1) {
        throw domain_error("Error! Invalid values p/q!");
    }

    // Base case : Empty list/Identical start and end node sublist indices
    if (nullptr == head || p == q) {
        return head;
    }

    // Problem is solved in 3 steps
    // 1. Skip the 1st (p - 1) nodes
    // 2. Reverse the sublist from p to q node.
    // 3. After reversal, connect (p-1) node to q node of original list.
    //    Connect p node of original list to (q+1) node
    // 4. Skip remaining nodes

    // 1. Skip the 1st (p - 1) nodes
    LLNode* currNode = head;
    LLNode* nodePriorToSublist = nullptr;
    for (int i = 1; currNode != nullptr && i < p; ++i) {
        nodePriorToSublist = currNode;
        currNode = currNode->next();
    }

    // currNode would be the p node and
    // nodePriorToSublist would be (p - 1) node
    LLNode* firstNodeOfSublist = currNode;

    // 2. Reverse the sublist from p to q node

    // Previously processed node
    LLNode* prevNode = nullptr;
    // Iterate over the sublist from p to q nodes sequentially
    // reversing the current node at each iteration
    for (int i = p; currNode != nullptr && i <= q; ++i) {
        // Store next node to be processed
        LLNode* nextNode = currNode->next();
        // Reverse list at current node
        currNode->setNext(prevNode);
        // Update previous node processed and next node to be processed
        prevNode = currNode;
        currNode = nextNode;
    }

    LLNode* lastNodeOfSublist = prevNode; // q node
    LLNode* firstNodeAfterSublist = currNode; // (q+1) node

    // Attach reversed sublist properly to main list
    // Connect (p-1) node to q node of original list.
    if (nodePriorToSublist) {
        nodePriorToSublist->setNext(lastNodeOfSublist);
    } else {
        head = lastNodeOfSublist;
    }
    // Connect p node of original list to (q+1) node
    if (firstNodeOfSublist) {
        firstNodeOfSublist->setNext(firstNodeAfterSublist);
    }

    return head;
}
