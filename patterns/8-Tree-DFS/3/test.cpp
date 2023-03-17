// System headers
#include <iostream>

// Local includes
#include "tree.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
testFn(TreeNode* tree, int tId) {
    cout << endl;
    long tpns = Tree::sumOfAllRootToTreePathNums(tree);
    cout << "Total sum of path numbers of all root to leaf paths for tree #"
        << tId << " = " << tpns << endl;
}

TreeNode*
constructTree1() {
    TreeNode *root, *left, *right;

    root = new TreeNode(1);
    left = new TreeNode(7);
    right = new TreeNode(9);
    root->setLeft(left);
    root->setRight(right);

    right->setLeft(new TreeNode(2));
    right->setRight(new TreeNode(9));

    return root;
}

TreeNode*
constructTree2() {
    TreeNode *root, *left, *right;

    root = new TreeNode(1);
    left = new TreeNode(0);
    right = new TreeNode(1);
    root->setLeft(left);
    root->setRight(right);

    left->setLeft(new TreeNode(1));

    right->setLeft(new TreeNode(6));
    right->setRight(new TreeNode(5));

    return root;
}

void
test() {
    TreeNode *tree;
    tree = constructTree1();
    testFn(tree, 1);
    tree = constructTree2();
    testFn(tree, 2);
}

int
main() {
    test();
    return 0;
}
