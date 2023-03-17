// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iostream>

// Local includes
#include "tree.h"

// Using declarations
using std::vector;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testFn(TreeNode* tree) {
    try {
        unsigned int minDepth = Tree::minDepth(tree);
        unsigned int maxDepth = Tree::maxDepth(tree);
        cout << "Minimum depth of tree is " << minDepth << endl;
        cout << "Maximum depth of tree is " << maxDepth << endl;
    } catch (domain_error& e) {
        throw e;
    }
}

TreeNode*
constructTestTree1() {

    TreeNode *root, *left, *right;
    root = new TreeNode(1);
    left = new TreeNode(2);
    right = new TreeNode(3);
    root->setLeftChild(left);
    root->setRightChild(right);

    left->setLeftChild(new TreeNode(4));
    left->setRightChild(new TreeNode(5));

    return root;
}

TreeNode*
constructTestTree2() {

    TreeNode *root, *left, *right;
    root = new TreeNode(12);
    left = new TreeNode(7);
    right = new TreeNode(1);
    root->setLeftChild(left);
    root->setRightChild(right);

    right->setLeftChild(new TreeNode(10));
    right->setRightChild(new TreeNode(5));

    return root;
}

TreeNode*
constructTestTree3() {

    TreeNode *root, *left, *right;
    root = new TreeNode(12);
    left = new TreeNode(7);
    right = new TreeNode(1);
    root->setLeftChild(left);
    root->setRightChild(right);

    left->setLeftChild(new TreeNode(9));

    TreeNode* tmpNode = new TreeNode(10);
    right->setLeftChild(tmpNode);
    tmpNode->setLeftChild(new TreeNode(11));

    right->setRightChild(new TreeNode(5));

    return root;
}

void
test() {
    TreeNode* root1 = constructTestTree1();
    TreeNode* root2 = constructTestTree2();
    TreeNode* root3 = constructTestTree3();
    try {
        testFn(root1);
        testFn(root2);
        testFn(root3);
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
