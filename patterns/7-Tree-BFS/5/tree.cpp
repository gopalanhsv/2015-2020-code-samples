// System headers
#include <queue>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::queue;
using std::domain_error;

// Statics, typedefs, globals

unsigned int
Tree::minDepth(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Add root to bfsQ
    bfsQ.push(root);

    unsigned int treeDepth = 0;
    // Iterate over all tree nodes via BFS
    while (!bfsQ.empty()) {
        // Increment tree depth
        ++treeDepth;

        qSzT numCurrLevelNodes = bfsQ.size();
        // Iterate over all tree nodes for the current level from L -> R
        for (qSzT i = 0; i != numCurrLevelNodes; ++i) {
            // Deque the node at front of BFS Q
            TreeNode* tNode = bfsQ.front();
            bfsQ.pop();

            // Minimum depth is attained at the point when first
            // leaf node is reached via level order/BFS traversal
            if (nullptr == tNode->left() && nullptr == tNode->right()) {
                return treeDepth;
            }

            // Add the dequeued nodes children (next level) to the BFS Q end
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }
        }
    }

    return treeDepth;
}

unsigned int
Tree::maxDepth(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Add root to bfsQ
    bfsQ.push(root);

    unsigned int treeDepth = 0;
    // Iterate over all tree nodes via BFS
    while (!bfsQ.empty()) {
        // Increment tree depth
        ++treeDepth;

        // Iterate over all tree nodes for the current level from L -> R
        qSzT numCurrLevelNodes = bfsQ.size();
        for (qSzT i = 0; i != numCurrLevelNodes; ++i) {
            // Deque the node at front of BFS Q
            TreeNode* tNode = bfsQ.front();
            bfsQ.pop();

            // Add the dequeued nodes children (next level) to the BFS Q end
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }
        }
    }

    // Max depth is attained at traversal end
    return treeDepth;
}
