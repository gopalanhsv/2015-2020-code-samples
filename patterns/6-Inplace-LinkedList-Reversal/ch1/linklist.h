#ifndef _LINKLIST_H_
#define _LINKLIST_H_

// System headers

// Local includes

// Using declarations

// Statics, typedefs, globals

class LLNode {
public:
    // Constructors
    LLNode(int v) : _val(v), _next(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline LLNode* next() const { return _next; }
    inline void setNext(LLNode* n) { _next = n; }
    inline void setVal(int v) { _val = v; }
    
private:
    LLNode();

    // Data members
    int _val;
    LLNode* _next;
};

class LinkedList {
public:
    static LLNode* reverseAlternatingKSizeSublist(LLNode* head, int k);
};

#endif /* _LINKLIST_H_ */
