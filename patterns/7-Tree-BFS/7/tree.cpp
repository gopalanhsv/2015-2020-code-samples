// System headers
#include <iostream>
#include <stdexcept>
#include <queue>

// Local includes
#include "tree.h"

// Using declarations
using std::domain_error;
using std::ostream;
using std::endl;
using std::queue;

// Statics, typedefs, globals

void
Tree::connectLevelOrderSiblings(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;

    // Enqueue root node onto the BFS Q
    bfsQ.push(root);
    // Perform BFS traversal over all nodes sequentially
    while (!bfsQ.empty()) {

        // Iterate over all nodes at current level from L->R
        // and string them as a linked list
        qSzT numNodesAtCurrLevel = bfsQ.size();
        TreeNode *prevNode = nullptr;
        for (qSzT i = 0; i != numNodesAtCurrLevel; ++i) {
            // Dequeue the node at front of BFS Q
            TreeNode *currNode = bfsQ.front();
            bfsQ.pop();
            // Link previous BFS node to current node
            if (nullptr != prevNode) {
                prevNode->setNext(currNode);
            }
            prevNode = currNode;

            // Enqueue children of current node to BFS Q
            if (nullptr != currNode->left()) {
                bfsQ.push(currNode->left());
            }
            if (nullptr != currNode->right()) {
                bfsQ.push(currNode->right());
            }
        }
    }
}

void
Tree::levelOrderTraversalViaNext(TreeNode* root, ostream& os) {
    os << endl;
    TreeNode *currLevelRoot = root;
    // Traverse each level from L -> R via siblings pointer till
    // all levels are done
    while (nullptr != currLevelRoot) {
        // Traversal of current level from L -> R 
        TreeNode *nextLevelRoot = nullptr;
        TreeNode *tNode = currLevelRoot;
        while (tNode) {
            os << tNode->value() << "-->";
            // Update the next level root to the first child
            // encountered of nodes encountered on the L -> R traversal
            if (nullptr == nextLevelRoot) {
                if (nullptr != tNode->left()) {
                    nextLevelRoot = tNode->left();
                } else {
                    nextLevelRoot = tNode->right();
                }
            }
            // Move onto next sibling
            tNode = tNode->next();
        }

        os << "null" << endl;

        // Update root of linked list to be traversed next
        currLevelRoot = nextLevelRoot;
    }
    os << endl;
}
