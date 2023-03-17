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
Tree::zigZagTraversal(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    vector<vector<int> > traversalOut;
    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Add root to bfsQ
    bfsQ.push(root);
    bool leftToRightTraversal = true;
    // Iterate over all tree nodes via BFS
    while (!bfsQ.empty()) {
        qSzT currLevelSize = bfsQ.size();
        // Allocate proper size for storing current level nodes
        // upfront as they can be stored either in L->R or R->L order
        vector<int> currLevelNodes(currLevelSize);
        // Iterate over all tree nodes for the current level from L -> R
        for (qSzT i = 0; i != currLevelSize; ++i) {
            // Dequeue the node at front of BFS Q
            TreeNode* tNode = bfsQ.front();
            bfsQ.pop();

            // Add the dequeued nodes children (next level) to the BFS Q end
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }

            // Add node value to current level traversal at appropriate
            // location based on current traversal direction
            if (leftToRightTraversal) {
                currLevelNodes[i] = tNode->value();
            } else {
                currLevelNodes[currLevelSize - 1 - i] = tNode->value();
            }
        }

        // Add the current level nodes to level order traversal output
        traversalOut.push_back(currLevelNodes);
        // Flip traversal direction for next iteration
        leftToRightTraversal = !leftToRightTraversal;
    }

    return traversalOut;
}
