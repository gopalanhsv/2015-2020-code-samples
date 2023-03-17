#ifndef _TREE_H_
#define _TREE_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals

class TreeNode {
public:
    // Constructor
    TreeNode(int v) : _val(v), _lChildP(nullptr), _rChildP(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline TreeNode* left() const { return _lChildP; }
    inline TreeNode* right() const { return _rChildP; }
    inline bool leafNode() const {
        return (nullptr == left() && nullptr == right()); }

    inline void setValue(int v) { _val = v; }
    inline void setLeft(TreeNode* t) { _lChildP = t; }
    inline void setRight(TreeNode* t) { _rChildP = t; }
private:
    TreeNode();

    // Data members
    int _val;
    TreeNode* _lChildP;
    TreeNode* _rChildP;
};

class Tree {
public:
    static std::vector<std::vector<TreeNode*> >
        allRootToLeafPathForPathSum(TreeNode* root, int psum);
private:
    static void allRootToLeafPathForPathSumRec(TreeNode* currNode,
        std::vector<std::vector<TreeNode*> >& allPaths,
        std::vector<TreeNode*>& currPath, int psum);
};

#endif /* _TREE_H_ */
