// System headers
#include <iostream>
#include <stdexcept>
#include <vector>

// Local includes
#include "tree.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;

// Statics, typedefs, globals

void
testFn(TreeNode* tree, int tId) {
    while (true) {
        int ps;
        cout << endl;
        cout << "Enter path sum from root to leaf to be found for in tree #"
             << tId << " :";
        if (cin >> ps) {
            unsigned int nPaths =
                Tree::nPathsFromTopToBottomForPathSum(tree, ps);
            cout << nPaths << " top to bottom sub paths with sum " << ps;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }
}

TreeNode*
constructTree1() {
    TreeNode *root, *left, *right;

    root = new TreeNode(1);
    left = new TreeNode(7);
    right = new TreeNode(9);
    root->setLeft(left);
    root->setRight(right);

    left->setLeft(new TreeNode(4));
    left->setRight(new TreeNode(5));

    right->setLeft(new TreeNode(2));
    right->setRight(new TreeNode(7));

    return root;
}

TreeNode*
constructTree2() {
    TreeNode *root, *left, *right;

    root = new TreeNode(12);
    left = new TreeNode(7);
    right = new TreeNode(1);
    root->setLeft(left);
    root->setRight(right);

    left->setLeft(new TreeNode(4));

    right->setLeft(new TreeNode(10));
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
