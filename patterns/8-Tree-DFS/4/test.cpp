// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

// Local includes
#include "tree.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::domain_error;
using std::iterator;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
    cin.ignore(10000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testFn(TreeNode* tree, int tId) {
    while (true) {
        cout << "Is path search for tree # " << tId << " to be done {y/x} ?";
        char ch;
        while (!(cin >> ch)) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if (ch != 'y') {
            break;
        }

        vector<int> pv;
        cout << endl << "Enter root to leaf path node vals sequentially to "
            << " be searched for!" << endl;
        readVec(pv);

        cout << "Input root to leaf path is ";
        printVec(pv);
        try {
            bool found = Tree::rootToLeafPathPresent(tree, pv);
            cout << "Input root to leaf path is "
                << (found ? "" : "not ") << "present in tree # "
                << tId << endl;
        } catch (domain_error& e) {
            throw e;
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
    TreeNode *tree1, *tree2;
    tree1 = constructTree1();
    tree2 = constructTree2();
    try {
        testFn(tree1, 1);
        testFn(tree2, 2);
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
