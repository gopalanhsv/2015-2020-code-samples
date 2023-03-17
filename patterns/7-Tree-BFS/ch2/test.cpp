// System headers
#include <vector>
#include <iostream>
#include <stdexcept>

// Local includes
#include "tree.h"

// Using declarations
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;

// Statics, typedefs, globals

void
displayTreeNodeVals(const vector<TreeNode*>& v) {
    cout << endl;
    for (auto tn : v) {
        cout << tn->value() << " ";
    }
    cout << endl;
}

void
testFn(TreeNode* tree, int tId) {
    try {
        vector<TreeNode*> rv = Tree::treeRightView(tree);
        cout << "Tree right view for tree #" << tId << " is : ";
        displayTreeNodeVals(rv);
    } catch (domain_error& e) {
        throw e;
    }
}

TreeNode*
constructTree1() {
    TreeNode *tNode, *root, *left, *right;

    root = new TreeNode(1);
    left = new TreeNode(2);
    right = new TreeNode(3);
    root->setLeft(left);
    root->setRight(right);

    left->setLeft(new TreeNode(4));
    left->setRight(new TreeNode(5));

    right->setLeft(new TreeNode(6));
    right->setRight(new TreeNode(7));

    return root;
}

TreeNode*
constructTree2() {
    TreeNode *tNode, *root, *left, *right;

    root = new TreeNode(12);
    left = new TreeNode(7);
    right = new TreeNode(1);
    root->setLeft(left);
    root->setRight(right);

    tNode = left;
    left = new TreeNode(9);
    tNode->setLeft(left);
    tNode = left;
    left = new TreeNode(3);
    tNode->setLeft(left);

    tNode = right;
    left = new TreeNode(10);
    right = new TreeNode(5);
    tNode->setLeft(left);
    tNode->setRight(right);
    
    return root;
}

void
test() {
    try {
        TreeNode *root;
        root = constructTree1();
        testFn(root, 1);
        root = constructTree2();
        testFn(root, 2);
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
