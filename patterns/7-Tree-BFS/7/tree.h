#ifndef _TREE_H_
#define _TREE_H_

// System headers
#include <iostream>

// Local includes

// Using declarations

// Statics, typedefs, globals

class TreeNode {
public:
    // Constructor
    TreeNode(int v) : _val(v), _leftChildP(nullptr),
        _rightChildP(nullptr), _nextP(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline TreeNode* left() const { return _leftChildP; }
    inline TreeNode* right() const { return _rightChildP; }
    inline TreeNode* next() const { return _nextP; }
    inline void setLeft(TreeNode* t) { _leftChildP = t; }
    inline void setRight(TreeNode* t) { _rightChildP = t; }
    inline void setNext(TreeNode* t) { _nextP = t; }

private:
    TreeNode();

    // Data members
    int _val;
    TreeNode* _leftChildP;
    TreeNode* _rightChildP;
    TreeNode* _nextP;
};

class Tree {
public:
    static void
        connectLevelOrderSiblings(TreeNode* root);

    static void
        levelOrderTraversalViaNext(TreeNode* root, std::ostream& os);
};

#endif /* _TREE_H_ */
