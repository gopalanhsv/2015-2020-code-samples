// System headers
#include <stdexcept>
#include <algorithm>

// Local includes
#include "tree.h"

// Using declarations
using std::max;
using std::domain_error;

// Statics, typedefs, globals

unsigned int maxDiameter = 0;

unsigned int
Tree::treeDiameter(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    // Compute the height of the subtrees commencing from root and use the
    // same to determine the max tree diameter
    computeSubtreeHeightRec(root);
    return maxDiameter;
}

unsigned int
Tree::computeSubtreeHeightRec(TreeNode* tNode) {
    // Reached null node, height is 0
    if (tNode == nullptr) {
        return 0;
    }

    // Diameter of subtree rooted at the current node would be
    // the sum of its left subtree height, its right subtree height and
    // the current node (1). Determine the the respective subtree heights
    // recursively
    unsigned int subTreeDiameter;
    unsigned int leftSubtreeHt = computeSubtreeHeightRec(tNode->left());
    unsigned int rightSubtreeHt = computeSubtreeHeightRec(tNode->right());
    subTreeDiameter = leftSubtreeHt + rightSubtreeHt + 1;

    // Update the tree diameter (if currently computed height of local
    // subtree is more)
    maxDiameter = max(maxDiameter, subTreeDiameter);

    // Height of subtree rooted at the current node would be 1 (to include
    // itself) + max subtree heights of either of its left/right subtrees
    return 1 + max(leftSubtreeHt, rightSubtreeHt);
}
