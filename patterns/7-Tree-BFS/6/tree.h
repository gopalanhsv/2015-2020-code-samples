#ifndef _TREE_H_
#define _TREE_H_

// System headers

// Local includes

// Using declarations

// Statics, typedefs, globals

class TreeNode {
public:
    // Constructor
    TreeNode(int v) : _val(v), _leftChildP(nullptr), _rightChildP(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline TreeNode* left() const { return _leftChildP; }
    inline TreeNode* right() const { return _rightChildP; }
    inline void setLeft(TreeNode* t) { _leftChildP = t; }
    inline void setRight(TreeNode* t) { _rightChildP = t; }

private:
    TreeNode();

    // Data members
    int _val;
    TreeNode* _leftChildP;
    TreeNode* _rightChildP;
};

class Tree {
public:
    static TreeNode*
        levelOrderSuccessor(TreeNode* root, int key);
};

#endif /* _TREE_H_ */
