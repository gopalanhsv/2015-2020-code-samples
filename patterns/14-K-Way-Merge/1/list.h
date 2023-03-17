#ifndef _LIST_H_
#define _LIST_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, globals, typedefs

class ListNode {
public:
    // Constructor
    ListNode(int v) : _val(v), _nextP(nullptr) {}

    // Accessors
    inline int val() const { return _val; }
    inline ListNode* next() const { return _nextP; }
    inline void setVal(int v) { _val = v; }
    inline void setNext(ListNode* nxt) { _nextP = nxt; }

private:
    ListNode();

    // Data members
    int _val;
    ListNode* _nextP;
};

class List {
public:
    static ListNode* mergeKSortedLists(const std::vector<ListNode*>& lists);
private:
};

#endif /* _LIST_H_ */
