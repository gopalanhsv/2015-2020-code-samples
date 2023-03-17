#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class LLNode {
public:
    LLNode(int v) : _val(v), _next(nullptr) {}

    inline int value() const { return _val; }
    inline LLNode* next() const { return _next; }
    inline void setVal(int v) { _val = v; }
    inline void setNext(LLNode* n) { _next = n; }

private:
    LLNode();

    // Data members
    int _val;
    LLNode* _next;
};

class LinkedList {
public:
    static LLNode* reverseSubList(LLNode* head, int p, int q);
private:
};

#endif /* _LINKED_LIST_H_ */
