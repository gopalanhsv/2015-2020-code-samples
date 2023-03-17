// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

vector<vector<TreeNode*> >
Tree::allRootToLeafPathForPathSum(TreeNode* root, int psum) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input vector!");
    }

    // Recursively find root->leaf paths with given sum
    // commencing from root
    vector<vector<TreeNode*> > allPaths;
    vector<TreeNode*> currPath;
    allRootToLeafPathForPathSumRec(root, allPaths, currPath, psum);

    return allPaths;
}

void
Tree::allRootToLeafPathForPathSumRec(TreeNode* currNode,
    vector<vector<TreeNode*> >& allPaths, vector<TreeNode*>& currPath,
    int psum) {

    // Base case of null subtree
    if (nullptr == currNode) {
        return;
    }

    // Add the current node to current path
    currPath.push_back(currNode);
    // Update path sum to account for current node value
    psum -= currNode->value();

    if (currNode->leafNode()) {
        // Current node is leaf node and path sum is 0, implies current root
        // to leaf path with given sum. Add current path from root to current
        // node to the set of paths being searched
        if (0 == psum) {
            allPaths.push_back(currPath);
        }

    } else {

        // Non leaf node
        // Recursively find root to leaf paths with the adjusted/remainder
        // path sum on left and right subtrees
        allRootToLeafPathForPathSumRec(
            currNode->left(), allPaths, currPath, psum);
        allRootToLeafPathForPathSumRec(
            currNode->right(), allPaths, currPath, psum);
    }

    // Remove the current node from current path prior to backtracking
    // up the call stack as the current node and its subtrees have been processed
    currPath.pop_back();
}
