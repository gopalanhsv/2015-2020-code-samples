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
Tree::connectAllLevelOrderSiblings(TreeNode* root) {
    if (nullptr == root) {
        throw domain_error("Error! Empty input tree!");
    }

    queue<TreeNode*> bfsQ;
    typedef queue<TreeNode*>::size_type qSzT;

    // Enqueue root node onto the BFS Q
    bfsQ.push(root);
    // Perform BFS traversal over all nodes sequentially
    TreeNode *prevNode = nullptr;
    while (!bfsQ.empty()) {
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

void
Tree::levelOrderTraversalViaNext(TreeNode* root, ostream& os) {
    os << endl;
    TreeNode *tNode = root;
    // Traverse the tree nodes via next sibling pointer
    while (nullptr != tNode) {
        os << tNode->value() << "-->";
        // Move to the next sibling
        tNode = tNode->next();
    }
    os << "null" << endl;
}
