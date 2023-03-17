// System headers

// Local includes
#include "linklist.h"

// Using declarations

// Statics, typedefs, globals

LLNode*
LinkedList::rotateList(LLNode* head, int nRotations) {

    // Base case - empty/single node list/0 rotations
    if (nullptr == head || nullptr == head->next() || 0 == nRotations) {
        return head;
    }

    // Count the number of nodes in list and find the last node
    LLNode* lastNode = head;
    int numNodes = 1;
    while (lastNode->next() != nullptr) {
        ++numNodes;
        lastNode = lastNode->next();
    }

    // Normalize the number of rotations if it exceeds node count or is -ve
    nRotations %= numNodes;
    nRotations += numNodes; // For handling -ve num rotations
    nRotations %= numNodes;

    // After rotating list by k nodes to right in a list of n nodes,
    // 1. Nodes n - k + 1 to n of original list come to list front
    // 2. Nodes 1 to n - k of original list go to list back
    // 3. Node n (last node) of original list gets conected to node 1
    //    (head node) of original list
    // 4. Node n - k (node prior to rotation point) of original list
    //    becomes tail node
    // 5. Node n - k + 1 (node at rotation point) of original list
    //    becomes head node


    // Connect tail node of list to head node to make it circular to
    // perform rotation
    lastNode->setNext(head);
    // Determine node prior to rotation point and node at rotation point
    LLNode* prevNode, *rotationPointNode;
    prevNode = lastNode;
    rotationPointNode = head;
    for (int i = 1; i <= numNodes - nRotations; ++i) {
        prevNode = rotationPointNode;
        rotationPointNode = rotationPointNode->next();
    }

    // Node prior to rotation point becomes tail node post rotation
    prevNode->setNext(nullptr);
    // Node at rotation point becomes head node post rotation
    return rotationPointNode;
}
