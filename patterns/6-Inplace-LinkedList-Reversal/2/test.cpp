// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "linklist.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

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
convertVecToLList(const vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }

    LLNode *head = new LLNode(v[0]);
    LLNode *node = head;
    for (vector<int>::size_type i = 1; i != v.size(); ++i) {
        node->setNext(new LLNode(v[i]));
        node = node->next();
    }
    return head;
}

void
displayLList(LLNode* llist) {
    cout << endl;
    while (nullptr != llist) {
        cout << llist->value() << "-->";
        llist = llist->next();
    }
    cout << "null" << endl;
}

void
testFn() {
    cout << "Enter list elements : ";
    vector<int> v;
    readVec(v);

    LLNode* ll = convertVecToLList(v);
    cout << "Input link list is : ";
    displayLList(ll);

    int p, q;
    cout << "Enter start index from where reversal commences : " << endl;
    while (!(cin >> p));
    cout << "Enter end index at which reversal stops : " << endl;
    while (!(cin >> q));

    ll = LinkedList::reverseSubList(ll, p, q);
    cout << "Reversed link list is : ";
    displayLList(ll);
}

int
main() {
    testFn();
    return 0;
}
