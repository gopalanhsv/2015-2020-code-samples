// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "list.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::domain_error;
using std::copy;
using std::sort;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

ListNode*
convertVecToList(const vector<int>& v) {
    ListNode *head = nullptr;
    ListNode *tail;
    for (auto e : v) {
        ListNode* newNode = new ListNode(e);
        if (nullptr == head) {
            head = newNode;
        } else {
            tail->setNext(newNode);
        }
        tail = newNode;
    }
    return head;
}

void
printList(ListNode* lst) {
    cout << endl;
    while (lst != nullptr) {
        cout << lst->val() << " --> ";
        lst = lst->next();
    }
    cout << " null " << endl;
}

void
test() {
    unsigned n;
    while (true) {
        cout << endl << "Enter number of lists to be sorted : ";
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try entering again!!!" << endl;
    }

    vector<ListNode*> listsV;
    while (n--) {
        cout << "Enter elems for list #" << n + 1 << " : ";
        vector<int> v;
        readVec(v);
        sort(v.begin(), v.end());
        ListNode* list = convertVecToList(v);
        listsV.push_back(list);
        cout << endl << "Sorted List #" << n + 1;
        printList(list);
    }

    try {
        ListNode *sl = List::mergeKSortedLists(listsV);
        cout << "Sorted merged list is ";
        printList(sl);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
