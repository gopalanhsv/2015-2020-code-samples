// System headers
#include <iostream>
#include <stdexcept>
#include <string>

// Local includes
#include "tree.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::to_string;

// Statics, typedefs, globals

TreeNode*
constructTree1() {
    TreeNode *tNode, *root, *left, *right;

    root = tNode = new TreeNode(1);
    left = new TreeNode(2);
    right = new TreeNode(3);
    tNode->setLeft(left);
    tNode->setRight(right);

    left->setLeft(new TreeNode(4));
    left->setRight(new TreeNode(5));

    right->setLeft(new TreeNode(6));
    right->setRight(new TreeNode(7));

    return root;
}

TreeNode*
constructTree2() {
    TreeNode *tNode, *root, *left, *right;

    root = tNode = new TreeNode(12);
    left = new TreeNode(7);
    right = new TreeNode(1);
    tNode->setLeft(left);
    tNode->setRight(right);

    tNode = left;
    left = new TreeNode(9);
    tNode->setLeft(left);

    tNode = right;
    left = new TreeNode(10);
    right = new TreeNode(5);
    tNode->setLeft(left);
    tNode->setRight(right);

    return root;
}

void
testFn(TreeNode* tree, unsigned int tId) {
    try {
        Tree::connectLevelOrderSiblings(tree);
        cout << "Level order traversal of tree #" << tId
            << " via siblings pointer is : ";
        Tree::levelOrderTraversalViaNext(tree, cout);
    } catch (domain_error& e) {
        throw e;
    }
}

void
test() {
    try {
        TreeNode *tree;
        tree = constructTree1();
        testFn(tree, 1);
        tree = constructTree2();
        testFn(tree, 2);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
