#ifndef _LINKLIST_H_
#define _LINKLIST_H_

// System headers

// Local includes

// Using declarations

// Statics, typedefs, globals

class LLNode {
public:
    // Constructor
    LLNode(int v) : _val(v), _next(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline LLNode* next() const { return _next; }
    inline void setVal(int v) { _val = v; }
    inline void setNext(LLNode* n) { _next = n; }

private:
    LLNode();

    int _val;
    LLNode* _next;
};

class LinkedList {
public:
    static LLNode* rotateList(LLNode* head, int nRotations);
private:
};

#endif /* _LINKLIST_H_ */
