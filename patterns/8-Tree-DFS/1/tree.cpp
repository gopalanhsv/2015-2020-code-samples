// System headers
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::domain_error;

// Statics, typedefs, globals

bool
Tree::rootToLeafPathExistsForPathSum(TreeNode* root, int psum) {
    if (nullptr == root) {
        return 0 == psum;
    }

    // Check recursively for existence of root->leaf path with given
    // sum commencing from root
    return rootToLeafPathExistsForPathSumRec(root, psum);
}

bool
Tree::rootToLeafPathExistsForPathSumRec(TreeNode* currNode, int psum) {
    if (nullptr == currNode) {
        return (psum == 0);
    }

    // Current node is a leaf
    if (currNode->leafNode()) {
        // Leaf node value equals the remainder root to leaf path sum 
        // implies presence of root to leaf path for given sum
        return (psum == currNode->value());
    }

    // Non leaf node
    // Recursively check on left and right subtrees for existence of root
    // to leaf path with remainder sum (after accounting for /reducing the
    // current node value)
    psum -= currNode->value();
    return
        (rootToLeafPathExistsForPathSumRec(currNode->left(), psum) ||
        rootToLeafPathExistsForPathSumRec(currNode->right(), psum));
}
