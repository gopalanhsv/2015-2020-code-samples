#ifndef _TREE_H_
#define _TREE_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals

class TreeNode {
public:
    // Constructors
    TreeNode(int value) : _val(value),
        _leftChildP(nullptr), _rightChildP(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline TreeNode* left() const { return _leftChildP; }
    inline TreeNode* right() const { return _rightChildP; }

    inline void setVal(int v) { _val = v; }
    inline void setLeftChild(TreeNode* lp) { _leftChildP = lp; }
    inline void setRightChild(TreeNode* rp) { _rightChildP = rp; }
    
private:
    TreeNode();

    // Data members
    int _val;
    TreeNode* _leftChildP;
    TreeNode* _rightChildP;
};

class Tree {
public:
    static std::vector<std::vector<int> >
        levelOrderTraverse(TreeNode* root);
private:
};

#endif /* _TREE_H_ */
