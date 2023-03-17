// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

bool
Tree::rootToLeafPathPresentRec(TreeNode* currNode, vector<int> pathNodeValVec,
        vector<int>::size_type pathNodeValVecIdx) {
    if (nullptr == currNode) {
        return false;
    }

    // End of specified path node value vector reached before hitting
    // leaf node => given path does not exist
    if (pathNodeValVecIdx == pathNodeValVec.size()) {
        return false;
    }
    // Current node value does not match the path node vector value at
    // appropriate index => given path does not exist
    if (pathNodeValVec[pathNodeValVecIdx] != currNode->value()) {
        return false;
    }

    // Current node is a leaf node
    if (currNode->leafNode()) {
        // Path node value vector has been fully examined
        if (pathNodeValVecIdx + 1 == pathNodeValVec.size()) {
            return true;
        } else {
            return false;
        }
    }

    // Current node is not a leaf node
    // Increment path node vector value index to indicate next
    // node value along path to leaf
    pathNodeValVecIdx += 1;
    // Recursively check the left and right subtrees for presence of
    // remainder path node values as specified down to leaf
    return
        rootToLeafPathPresentRec(currNode->left(),
            pathNodeValVec, pathNodeValVecIdx) ||
        rootToLeafPathPresentRec(currNode->right(),
            pathNodeValVec, pathNodeValVecIdx);
}

bool
Tree::rootToLeafPathPresent(TreeNode* root, vector<int> pathNodeValVec) {
    if (nullptr == root || pathNodeValVec.empty()) {
        throw domain_error("Error! Empty input tree/root to leaf path!");
    }

    // Recursively check or existence of given root to leaf path
    // commencing from the root
    return rootToLeafPathPresentRec(root, pathNodeValVec, 0);
}
