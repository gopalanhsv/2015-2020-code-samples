// System headers

// Local includes
#include "linkedList.h"

// Using declarations

// Statics, typedefs, globals

LLNode*
LinkedList::reverse(LLNode* head) {
    LLNode* prevNode = nullptr;
    LLNode* currNode = head;
    while (currNode != nullptr) {
        // Store next node to current node
        LLNode* nextNode = currNode->next();
        // Reverse link between current and previous node
        currNode->setNext(prevNode);
        // Update previous and current node pointers for
        // next iteration
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}

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

bool
LinkedList::isPalindromic(LLNode* head) {
    // Base case (null or single node list)
    if ((nullptr == head) || (nullptr == head->next())) {
        return true;
    }

    // Find the middle node of linked list
    // Reverse the linked list from its middle to end
    LLNode* midNode = middleNode(head);
    LLNode* secondHalfReversedHead = reverse(midNode);

    // Compare the linked list elements from either end element
    // by element to the middle to see if the linked list is palindromic
    LLNode* firstHalfNode = head;
    LLNode* secondHalfNode = secondHalfReversedHead;
    while ((firstHalfNode != nullptr) && (secondHalfNode != nullptr)) {
        if (firstHalfNode->value() != secondHalfNode->value()) {
            // Non-palindromic list, break out
            break;
        }
        // Advance to list centre from both ends
        firstHalfNode = firstHalfNode->next();
        secondHalfNode = secondHalfNode->next();
    }

    // Reverse the modified linked list from its middle to end node so
    // that it reverts to the original linked list
    reverse(secondHalfReversedHead);

    // Halves of the list from either end had same elements, so check
    // proceeded right on till the end => palindromic list
    if (firstHalfNode == nullptr && secondHalfNode == nullptr) {
        return true;
    }

    return false;
}
