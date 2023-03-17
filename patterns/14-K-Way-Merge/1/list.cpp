// System headers
#include <vector>
#include <queue>
#include <stdexcept>

// Local includes
#include "list.h"

// Using declarations
using std::vector;
using std::priority_queue;
using std::domain_error;

// Statics, globals, typedefs

ListNode*
List::mergeKSortedLists(const std::vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }

    // Maintain a Min heap/PQ of one least element each amongst the
    // currently unprocessed elements from each of 'K' lists
    struct ListNodeCmp {
        // List node with lower value has higher priority
        bool operator() (const ListNode* n1, const ListNode* n2) const {
            return n1->val() > n2->val();
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> minHeap;

    // Add the 1st (min) element from each of the lists to the heap
    for (auto listHeadNode : lists) {
        minHeap.push(listHeadNode);
    }

    ListNode *sortedListHead = nullptr;
    ListNode *sortedListTail = nullptr;
    while (!minHeap.empty()) {
        // Pop least value element from heap top
        auto minNode = minHeap.top();
        minHeap.pop();

        // Replace popped least value element in the heap with the next 
        // unprocessed least value element from same list to which
        // popped least value element belonged to
        if (nullptr != minNode->next()) {
            minHeap.push(minNode->next());
        }

        // Add popped least value element to tail of sorted merged list
        minNode->setNext(nullptr);
        if (nullptr == sortedListHead) {
            sortedListHead = minNode;
            sortedListTail = minNode;
        } else {
            sortedListTail->setNext(minNode);
            sortedListTail = minNode;
        }
    }

    return sortedListHead;
}
