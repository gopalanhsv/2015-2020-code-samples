// System headers
#include <iostream>

// Local includes
#include "linkedList.h"

// Using declarations
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
printList(LLNode* head) {
    cout << endl;
    while (head != nullptr) {
        cout << head->value() << "-->";
        head = head->next();
    }
    cout << endl;
}

void
testForCycle() {

    // Create a normal linked list without cycles
    LLNode* node = new LLNode(1);
    LLNode* head = node;

    node->setNext(new LLNode(2));
    node = node->next();
    node->setNext(new LLNode(3));
    node = node->next();
    node->setNext(new LLNode(4));
    node = node->next();
    node->setNext(new LLNode(5));
    node = node->next();
    node->setNext(new LLNode(6));
    node = node->next();
    printList(head);

    // Check for presence of cycle
    bool c = LinkedList::hasCycle(head);
    cout << "Linked List #1 "
        << (c ? "has": "does not have") << " a cycle" << endl;
    cout << "Cycle count is " << LinkedList::cycleLength(head) << endl;

    // Introduce a loop at tail of 1st list and check for cycle presence
    node->setNext(head->next()->next());
    c = LinkedList::hasCycle(head);
    cout << "Linked List #2 "
        << (c ? "has": "does not have") << " a cycle" << endl;
    cout << "Cycle count is " << LinkedList::cycleLength(head) << endl;

    // Introduce a loop at tail of 1st list and check for cycle presence
    node->setNext(head->next()->next()->next());
    c = LinkedList::hasCycle(head);
    cout << "Linked List #3 "
        << (c ? "has": "does not have") << " a cycle" << endl;
    cout << "Cycle count is " << LinkedList::cycleLength(head) << endl;
}

int
main() {
    testForCycle();
    return 0;
}
