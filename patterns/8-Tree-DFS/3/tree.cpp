// System headers
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::domain_error;

// Statics, typedefs, globals

long
Tree::sumOfAllRootToTreePathNums(TreeNode* root) {
    // Empty tree => nil path numbers
    if (nullptr == root) {
        return 0;
    }

    // Recursively compute total sum of all root to leaf path
    // numbers commencing from root
    long currPathNum = 0;
    return sumOfAllRootToTreePathNumsRec(root, currPathNum);
}

long
Tree::sumOfAllRootToTreePathNumsRec(TreeNode* currNode, long currPathNum) {
    if (nullptr == currNode) {
        return 0;
    }

    // Update path number for current path to account for current node
    currPathNum = 10 * currPathNum + currNode->value();

    if (currNode->leafNode()) {
        // Current node is a leaf, path ends here. Return path number
        // of path terminating at this leaf
        return currPathNum;
    }

    // Non leaf node
    // Total sum of path numbers would be sum of path numbers of all paths
    // commencing from root and passing through this non-leaf nodes to the
    // leaves (via subtrees rooted at this non leaf node). So recursively
    // sum up path numbers of subtrees rooted at this non leaf nodes
    return
        sumOfAllRootToTreePathNumsRec(currNode->left(), currPathNum) +
        sumOfAllRootToTreePathNumsRec(currNode->right(), currPathNum);
}
