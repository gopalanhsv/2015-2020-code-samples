#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

// System headers

class LLNode {
public:
    // Constructor
    LLNode(int value) : _val(value), _next(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline LLNode* next() const { return _next; }
    inline void setNext(LLNode* nxt) { _next = nxt; }

private:
    LLNode();

    // Data members
    int _val;
    LLNode* _next;
};

class LinkedList {
public:
    static LLNode* middleNode(LLNode* head);
private:
};

#endif /* _LINKED_LIST_H_ */
