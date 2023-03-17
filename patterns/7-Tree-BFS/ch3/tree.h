#ifndef _TREE_H_
#define _TREE_H_

// System headers
#include <vector>
#include <utility>

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

    inline void setValue(int v) { _val = v; }
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
    static std::vector<TreeNode*> treeBoundary(TreeNode* root);

private:
    static std::vector<TreeNode*>
        leafNodesInLeftToRightOrderViaDFS(TreeNode* root);

    static std::pair<std::vector<TreeNode*>, std::vector<TreeNode*> >
        leftAndRightViewNodes(TreeNode *root);
};

#endif /* _TREE_H_ */
