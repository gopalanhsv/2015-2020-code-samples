// System headers
#include <stdexcept>

// Local includes
#include "linklist.h"

// Using declarations
using std::domain_error;

// Statics, typedefs, globals

LLNode*
LinkedList::reverseAlternatingKSizeSublist(LLNode* head, int k) {
    if (k < 0) {
        throw domain_error("Invalid sublist size value");
    }

    // Base case - single element/empty list
    if (nullptr == head || nullptr == head->next() || 1 == k) {
        return head;
    }

    // The process for reverseing alternating 'k' size sublists would be -
    // A. Reverse a 'k' size sublist
    //    - Store the last/k node of previous sublist(sublist whose k
    //      nodes were skipped without reversing) - node 1
    //    - Store first node of current sublist (sublist whose k nodes
    //      are going to be reversed), which will become last sublist
    //      node after reversal - node 2
    //    - Reverse the k node of current sublist
    //    - Store the last/k node of current sublist being reversed/which
    //      become first sublist node after reversal - node 3
    //    - Store the first node next sublist (next k-sublist which is going
    //      to be skipped) - node 4
    //    - Connect reversed sublist to original list
    //      -- Connect node 1 to node 3
    //      -- Connect node 2 to node 4
    //
    // B. Skip 'k' nodes
    // Repeat above steps A & B till end of list reached

    LLNode* lastNodeOfPrevSublist = nullptr;
    LLNode* firstNodeOfSublist = head;
    while (true) {
        // Reverse 'k' sized sublist
        LLNode* prevNode = nullptr;
        LLNode* currNode = firstNodeOfSublist;
        for (int i = 1; currNode != nullptr && i <= k; ++i) {
            // Store next node to node being processed
            LLNode* nextNode = currNode->next();
            // Reverse the links of node being processed
            currNode->setNext(prevNode);
            // Update previous node to node processed
            prevNode = currNode;
            // Update current node to next node to be processed
            currNode = nextNode;
        }

        LLNode* lastNodeOfSublist = prevNode;
        LLNode* firstNodeOfNextSublist = currNode;

        // Attach the reverse sublist to original linked list

        // Connect last node of previous sublist (which was not reversed) to
        // first node of current reversed sublist (i.e. last/kth node of same
        // sublist prior to reversal)
        if (nullptr != lastNodeOfPrevSublist) {
            lastNodeOfPrevSublist->setNext(lastNodeOfSublist);
        } else {
            head = lastNodeOfSublist;
        }

        // Connect last node of current reversed sublist (i.e first node of
        // sublist prior to reversal) to the first node of next sublist which
        // is not going to be reversed
        firstNodeOfSublist->setNext(firstNodeOfNextSublist);

        // Skip the next sublist of 'k - 1' nodes and reach the 'k' node of
        // the skipped sublist
        currNode = firstNodeOfNextSublist;
        for (int i = 1; currNode != nullptr && i < k; ++i) {
            currNode = currNode->next();
        }
        // Reached end of list
        if (nullptr == currNode || nullptr == currNode->next()) {
            break;
        }

        // Update last node of previous sublist
        lastNodeOfPrevSublist = currNode;
        // Update the node from which processing should commence next
        firstNodeOfSublist = currNode->next();
    }

    return head;
}
