// System headers
#include <stdexcept>

// Local includes
#include "linklist.h"

// Using declarations
using std::domain_error;

// Statics, typedefs, globals

LLNode*
LinkedList::reverseEveryKSizeSubList(LLNode* head, int k) {
    if (k < 0) {
        throw domain_error("Error! Invalid value k!");
    }

    // Base case : Empty list, single element sublist reversal
    if (nullptr == head || k == 1) {
        return head;
    }

    // Problem is solved in following steps
    // Store last node/kth node of previous sublist - 1
    // Store first node of sublist being processed  - 2
    // Reverse the k nodes of sublist being processed
    // Store the last/kth node of current sublist - 3
    // Store the first node new/next sublist - 4
    // Now we need to add the reversed sublist back to original list
    // Connect node 1 to node 3. Connect node 2 to node 4

    LLNode* lastNodeOfPrevSublist = nullptr;
    LLNode* firstNodeOfSublist = head;

    while (true) {

        LLNode* currNode = firstNodeOfSublist;
        // Reverse the k nodes of current sublist being processed
        LLNode* prevNode = nullptr;
        // Iterate over the k nodes of the sublist sequentially reversing
        // the link at each node step by step
        for (int i = 1; currNode != nullptr && i <= k; ++i) {
            // Store next node in a temp variable
            LLNode *nextNode = currNode->next();
            // Reverse links at current node
            currNode->setNext(prevNode);
            // Update previously processed node to current node
            prevNode = currNode;
            // Update current node to next node to be processed
            currNode = nextNode;
        }

        // Store the last/kth node of currently processed sublist and 
        // 1st node of next sublist to be processed
        LLNode* lastNodeOfSublist = prevNode;
        LLNode* firstNodeOfNextSublist = currNode;

        // Connect the last/kth node of previously processed sublist to
        // last kth (now 1st after reversal) of currently reversed sublist
        if (lastNodeOfPrevSublist) {
            lastNodeOfPrevSublist->setNext(lastNodeOfSublist);
        } else {
            head = lastNodeOfSublist;
        }
        // Update the last/kth node of previously processed sublist
        lastNodeOfPrevSublist = firstNodeOfSublist;

        // Connect the 1st (now last after reversal) of currently
        // processed sublist to first node of next sublist to be processed
        firstNodeOfSublist->setNext(firstNodeOfNextSublist);
        if (nullptr == firstNodeOfNextSublist) {
            // Reached end of list
            break;
        } else {
            // Update the 1st node of sublist to be processed next
            firstNodeOfSublist = firstNodeOfNextSublist;
        }
    }

    return head;
}
