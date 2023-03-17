// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

unsigned int
Tree::nSubPathsFromTopToBottomForPathSum(TreeNode* currNode,
    vector<TreeNode*>& currPathNodes, int psum) {
    // Reached leaf/node with one child in prior step
    if (nullptr == currNode) {
        return 0;
    }

    // Add the current node to the set of path nodes on
    // traversing down from root to the leaf
    currPathNodes.push_back(currNode);

    // Determine the number of top to bottom sub paths terminating
    // at the current node with the specified path sum value
    unsigned nPaths = 0;
    int subPathSum = 0;
    for (vector<TreeNode*>::reverse_iterator it = currPathNodes.rbegin();
        it != currPathNodes.rend(); ++it) {
        subPathSum += (*it)->value();
        if (subPathSum == psum) {
            ++nPaths;
        }
    }

    // Recursively determine the number of top to bottom sub paths 
    // with specified sum terminating in each of the subtree nodes
    nPaths +=
        nSubPathsFromTopToBottomForPathSum(
            currNode->left(), currPathNodes, psum);
    nPaths +=
        nSubPathsFromTopToBottomForPathSum(
            currNode->right(), currPathNodes, psum);

    // Remove current node from set of path nodes prior to backtracking
    // up the function call stack
    currPathNodes.pop_back();

    return nPaths;
}

unsigned int
Tree::nPathsFromTopToBottomForPathSum(TreeNode* root, int psum) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input vector!");
    }

    // Recursively count the number of sub paths (top to bottom only)
    // with the given sum commencing at root
    vector<TreeNode*> currPathNodes;
    return nSubPathsFromTopToBottomForPathSum(root, currPathNodes, psum);
}
