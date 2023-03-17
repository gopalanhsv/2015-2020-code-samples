// System headers
#include <stdexcept>
#include <vector>
#include <queue>

// Local includes
#include "tree.h"

// Using declartions
using std::domain_error;
using std::vector;
using std::queue;

// Statics, typedefs, globals

vector<TreeNode*>
Tree::treeRightView(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef std::queue<TreeNode*>::size_type qSzT;
    // Enqueue root to BFS Q
    bfsQ.push(root);

    // Iterate over all nodes in the tree via BFS/level order traversal
    vector<TreeNode*> treeRtNodes;
    // Till all nodes are not traversed
    while (!bfsQ.empty()) {
        // Examine all nodes at current level from L->R sequentially
        qSzT numNodesAtCurrLevel = bfsQ.size();
        TreeNode *tNode;
        for (qSzT i = 0; i != numNodesAtCurrLevel; ++i) {
            // Dequeue node at BFS Q front
            tNode = bfsQ.front();
            bfsQ.pop();

            // Add children of dequeued node to BFS Q for next level
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }
        }

        // Last node visited at current level would be at right extremity
        treeRtNodes.push_back(tNode);
    }

    return treeRtNodes;
}
