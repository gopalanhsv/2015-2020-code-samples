// System headers
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

// Local includes
#include "linklist.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

// Statics, typedefs, globals
void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

LLNode*
convertVecToLList(vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }

    LLNode* node, *head;
    head = node = new LLNode(v[0]);
    for (vector<int>::size_type i = 1; i != v.size(); ++i) {
        node->setNext(new LLNode(v[i]));
        node = node->next();
    }

    return head;
}

void
displayLList(const LLNode* llist) {
    cout << endl;
    while (nullptr != llist) {
        cout << llist->value() << "-->";
        llist = llist->next();
    }
    cout << "null" << endl;
}

void
testFn() {
    vector<int> v;
    cout << "Enter link list elements : ";
    readVec(v);
    cout << "List elements are : ";
    printVec(v);
    LLNode* llist = convertVecToLList(v);
    cout << "Input link list is : ";
    displayLList(llist);

    cout << "Enter size of sublist to be reversed alternately : ";
    int k;
    while (!(cin >> k));

    llist = LinkedList::reverseAlternatingKSizeSublist(llist, k);

    cout << "Input link list with alternating " << k <<
        " element sublists reversed is : ";
    displayLList(llist);
}

int
main() {
    testFn();
    return 0;
}
