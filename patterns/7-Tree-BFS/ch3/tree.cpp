// System headers
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <iterator>

// Local includes
#include "tree.h"

// Using declarations
using std::domain_error;
using std::vector;
using std::queue;
using std::stack;
using std::make_pair;
using std::pair;
using std::copy;
using std::back_inserter;

// Statics, typedefs, globals

vector<TreeNode*>
Tree::leafNodesInLeftToRightOrderViaDFS(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    vector<TreeNode*> leafNodes;
    // Execute a DFS of the tree to determine leaf nodes. While
    // performing the DFS, stack the right child and then the left
    // child to ensure that leaves are visited (and outputted in
    // result vector) in left to right order
    stack<TreeNode*> dfsStk;
    // Add root to DFS stack to commence DFS
    dfsStk.push(root);
    while (!dfsStk.empty()) {
        // Pop off node at DFS stack top
        TreeNode* tNode = dfsStk.top();
        dfsStk.pop();

        if (nullptr == tNode->left() && nullptr == tNode->right()) {
            // Leaf node
            leafNodes.push_back(tNode);
        } else {
            // Add children of non-leaf nodes to stack (right and
            // then left to ensure visit in L->R direction)
            if (nullptr != tNode->right()) {
                dfsStk.push(tNode->right());
            }
            if (nullptr != tNode->left()) {
                dfsStk.push(tNode->left());
            }
        }
    }

    return leafNodes;
}

pair<vector<TreeNode*>, vector<TreeNode*> >
Tree::leftAndRightViewNodes(TreeNode *root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef std::queue<TreeNode*>::size_type qSzT;
    // Enqueue root to BFS Q
    bfsQ.push(root);

    // Iterate over all nodes in the tree via BFS/level order traversal
    vector<TreeNode*> treeRightNodes;
    vector<TreeNode*> treeLeftNodes;
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

            // Skip leaf nodes from left and right views
            if (nullptr != tNode->left() || nullptr != tNode->right()) {
                if (0 == i) {
                    // First node visited at a level would be in left view
                    treeLeftNodes.push_back(tNode);
                } else if (numNodesAtCurrLevel - 1 == i) {
                    // Last node visited at a level would be in right view
                    // Node already in left view is excluded
                    treeRightNodes.push_back(tNode);
                }
            }
        }
    }

    return make_pair(treeLeftNodes, treeRightNodes);
}

vector<TreeNode*>
Tree::treeBoundary(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    // Tree boundary nodes are obtained by combining
    // following sequentially
    // 1. Left view nodes (excluding leaves)
    // 2. Leaves in left to right traversal order
    // 3. Right view nodes (excluding leaves and nodes already
    //    in left view)

    // Determine leaf nodes in L->R order
    vector<TreeNode*> leafNodes = leafNodesInLeftToRightOrderViaDFS(root);

    // Determine left and right view nodes
    pair<vector<TreeNode*>, vector<TreeNode*> > tNodeVecPair;
    tNodeVecPair = leftAndRightViewNodes(root);
    vector<TreeNode*>& leftView = tNodeVecPair.first;
    vector<TreeNode*>& rightView = tNodeVecPair.second;

    // Combine left view nodes, then leaf nodes and right view nodes
    // in sequential order to get boundary nodes
    // Right view nodes should be added in reverse order/bottom to upper
    // level order so that boundary nodes are anticlockwise
    vector<TreeNode*> boundary;
    copy(leftView.begin(), leftView.end(), back_inserter(boundary));
    copy(leafNodes.begin(), leafNodes.end(), back_inserter(boundary));
    copy(rightView.rbegin(), rightView.rend(), back_inserter(boundary));

    return boundary;
}
