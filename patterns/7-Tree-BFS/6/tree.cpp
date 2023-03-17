// System headers
#include <stdexcept>
#include <queue>

// Local includes
#include "tree.h"

// Using declarations
using std::domain_error;
using std::queue;

// Statics, typedefs, globals

TreeNode*
Tree::levelOrderSuccessor(TreeNode* root, int key) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Commence level order traversal by enqueueing root to BFS Q
    bfsQ.push(root);

    // Iterate over all nodes via BFS till BFS Q is not empty
    while (!bfsQ.empty()) {
        // Examine and dequeue off all the nodes in BFS Q at current level
        // one by one from L->R
        qSzT numNodesAtCurrLevel = bfsQ.size();
        for (qSzT i = 0; i != numNodesAtCurrLevel; ++i) {
            // Dequeue the node at front of BFS Q
            TreeNode* tNode = bfsQ.front();
            bfsQ.pop();

            // Add children of dequeued node to BFS Q
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }

            // Key whose level order successor is to searched for found
            if (tNode->value() == key) {
                if (bfsQ.empty()) {
                    return nullptr;
                }
                // Level order successor of this node would be at the
                // head of BFS A
                return bfsQ.front();
            }
        }
    }

    // Key not found
    return nullptr;
}
