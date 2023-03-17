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
        vector<TreeNode*> tb = Tree::treeBoundary(tree);
        cout << "Tree boundary for tree #" << tId << " is : ";
        displayTreeNodeVals(tb);
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
    left->left()->setLeft(new TreeNode(8));
    left->left()->setRight(new TreeNode(9));

    left->setRight(new TreeNode(5));
    left->right()->setLeft(new TreeNode(10));

    right->setLeft(new TreeNode(6));
    right->left()->setRight(new TreeNode(11));

    right->setRight(new TreeNode(7));
    right->right()->setLeft(new TreeNode(12));
    right->right()->setRight(new TreeNode(13));

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

    left->setLeft(new TreeNode(4));
    left->setRight(new TreeNode(3));
    left->left()->setLeft(new TreeNode(9));
    left->right()->setLeft(new TreeNode(15));

    right->setLeft(new TreeNode(10));
    right->setRight(new TreeNode(5));
    right->right()->setRight(new TreeNode(6));

    return root;
}

TreeNode*
constructTree3() {
    TreeNode *root, *left, *right;

    root = new TreeNode(12);
    right = new TreeNode(1);
    root->setRight(right);

    right->setLeft(new TreeNode(10));
    right->setRight(new TreeNode(5));

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
        root = constructTree3();
        testFn(root, 3);
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
