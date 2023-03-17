// System headers
#include <stdexcept>
#include <algorithm>
#include <limits>

// Local includes
#include "tree.h"

// Using declarations
using std::max;
using std::domain_error;
using std::numeric_limits;

// Statics, typedefs, globals

long maxPathSum = std::numeric_limits<long>::min();

long
Tree::treeMaxPathSum(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    // Compute the maximum path sum of subtrees hanging off from
    // root recursively and use same to determine max path sum
    computeSubtreeMaxPathSumRec(root);
    return maxPathSum;
}

long
Tree::computeSubtreeMaxPathSumRec(TreeNode* subTreeRoot) {
    // Reached null node, path sum commencing from it is 0
    if (subTreeRoot == nullptr) {
        return 0;
    }

    // Max local path sum including the subtree root would be sum of -
    // 1. Subtree root node val
    // 2. Max path sum of path commencing from left child of subtree root
    //    (exclude the left child path if -ve)
    // 3. Max path sum of path commencing from right child of subtree root
    //    (exclude the right child path if -ve)

    long pathSumLeftChild = computeSubtreeMaxPathSumRec(subTreeRoot->left());
    pathSumLeftChild = max(0L, pathSumLeftChild);
    long pathSumRightChild = computeSubtreeMaxPathSumRec(subTreeRoot->right());
    pathSumRightChild = max(0L, pathSumRightChild);

    long maxLocalPathSum =
        subTreeRoot->value() + pathSumLeftChild + pathSumRightChild;

    // Update the maximum path sum to the computed local subtree path sum
    // if it is more
    maxPathSum = max(maxPathSum, maxLocalPathSum);

    // Return the maximum path sum commencing from the current subtree root
    // Path would be commencing at the subtree root and going down to either
    // the left or right (whichever gives maximum path value), but not both
    return subTreeRoot->value() + max(pathSumLeftChild, pathSumRightChild);
}
