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

LLNode*
LinkedList::insert2ndListElementsInBetween1st(
    LLNode* firstListHead, LLNode* secondListHead) {

    LLNode* firstListNode = firstListHead;
    LLNode* secondListNode = secondListHead;
    while ((firstListNode != nullptr) && (secondListNode != nullptr)) {

        // Store the next node of 1st list in temp variable
        LLNode* firstListNextNode = firstListNode->next();
        // Store the next node of 2nd list in temp variable
        LLNode* secondListNextNode = secondListNode->next();

        // Remove head node of 2nd list and insert it
        // after the current 1st list node
        firstListNode->setNext(secondListNode);
        secondListNode->setNext(firstListNextNode);

        // Update the 1st/2nd list nodes to the respective next nodes in
        // 1st/2nd list which were initially stored in temp variables
        firstListNode = firstListNextNode;
        secondListNode = secondListNextNode;
    }

    // Update the tail node next (it will be always from 1st list as we
    // are inserting elements from 2nd list to in between 1st elements)
    if (firstListNode != nullptr) {
        firstListNode->setNext(nullptr);
    }

    return firstListHead;
}

LLNode*
LinkedList::rearrange(LLNode* head) {
    // Base case (null or single node list)
    if ((nullptr == head) || (nullptr == head->next())) {
        return head;
    }

    // Find the middle node of linked list
    // Reverse the linked list from its middle to end
    LLNode* midNode = middleNode(head);
    LLNode* secondHalfReversedHead = reverse(midNode);

    // Insert the elements one by one from the reversed list from
    // middle to end of original list (i.e secondHalfReversedHead);
    // in between the nodes of the list from beginning to middle of
    // original list (i.e head)
    return insert2ndListElementsInBetween1st(head, secondHalfReversedHead);
}
