// System headers
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::queue;
using std::domain_error;
using std::max;

// Statics, typedefs, globals

vector<double>
Tree::computeLevelAverages(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    vector<double> levelAvgV;
    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Add root to bfsQ
    bfsQ.push(root);
    // Iterate over all tree nodes via BFS
    while (!bfsQ.empty()) {
        qSzT numCurrLevelNodes = bfsQ.size();
        double levelSum = 0.0;
        // Iterate over all tree nodes for the current level from L -> R
        for (qSzT i = 0; i != numCurrLevelNodes; ++i) {
            // Deque the node at front of BFS Q
            TreeNode* tNode = bfsQ.front();
            bfsQ.pop();

            // Add the dequeued nodes' children (next level) to the BFS Q end
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }

            // Maintain running sum of all nodes at current level
            levelSum += tNode->value();
        }

        // Compute and store the current level average
        levelAvgV.push_back(levelSum / numCurrLevelNodes);
    }

    return levelAvgV;
}

vector<int>
Tree::computeMaxAtEachLevel(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    vector<int> levelMaxV;
    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;
    // Add root to bfsQ
    bfsQ.push(root);
    // Iterate over all tree nodes via BFS
    while (!bfsQ.empty()) {
        qSzT numCurrLevelNodes = bfsQ.size();
        int levelMax = (bfsQ.front())->value();
        // Iterate over all tree nodes for the current level from L -> R
        for (qSzT i = 0; i != numCurrLevelNodes; ++i) {
            // Deque the node at front of BFS Q
            TreeNode* tNode = bfsQ.front();
            bfsQ.pop();

            // Add the dequeued nodes' children (next level) to the BFS Q end
            if (nullptr != tNode->left()) {
                bfsQ.push(tNode->left());
            }
            if (nullptr != tNode->right()) {
                bfsQ.push(tNode->right());
            }

            // Store max of all nodes seen so far at current level
            levelMax = max(levelMax, tNode->value());
        }

        // Store the current level max value
        levelMaxV.push_back(levelMax);
    }

    return levelMaxV;
}
