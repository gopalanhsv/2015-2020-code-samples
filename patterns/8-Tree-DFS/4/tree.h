#ifndef _TREE_H_
#define _TREE_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals

class TreeNode {
public:
    TreeNode(int v) : _val(v), _lChildP(nullptr), _rChildP(nullptr) {}

    // Accessors
    inline int value() const { return _val; }
    inline TreeNode* left() const { return _lChildP; }
    inline TreeNode* right() const { return _rChildP; }
    inline bool leafNode() const {
        return (nullptr == left() && nullptr == right());
    }

    inline void setVal(int v) { _val = v; }
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
    static bool rootToLeafPathPresent(TreeNode* root,
        const std::vector<int> pathNodeValVec);
private:
    static bool rootToLeafPathPresentRec(TreeNode* currNode,
        const std::vector<int> pathNodeValVec,
        std::vector<int>::size_type pathNodeValVecIdx);
};

#endif /* _TREE_H_ */
