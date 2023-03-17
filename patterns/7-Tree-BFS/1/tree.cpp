// System headers
#include <vector>
#include <queue>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::queue;
using std::domain_error;

// Statics, typedefs, globals

vector<vector<int> >
Tree::levelOrderTraverse(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    vector<vector<int> > traversalOut;
    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Add root to bfsQ
    bfsQ.push(root);
    // Iterate over all tree nodes via BFS
    while (!bfsQ.empty()) {
        vector<int> currLevelNodes;
        qSzT currLevelSize = bfsQ.size();
        // Iterate over all tree nodes for the current level from L -> R
        for (qSzT i = 0; i != currLevelSize; ++i) {
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

            // Add node value to current level
            currLevelNodes.push_back(tNode->value());
        }

        // Add the current level nodes to level order traversal output
        traversalOut.push_back(currLevelNodes);
    }

    return traversalOut;
}
