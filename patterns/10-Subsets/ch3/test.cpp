// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "bst.h"

// Using declarations
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
test() {
    while (true) {
        cout << "Enter number of BST tree nodes : ";
        long n;
        if (cin >> n) {
            try {
                //long long nt = BST::numUniqueTrees(n);
                long long nt = BST::numUniqueTreesDPMemoization(n);
                cout << endl;
                cout << nt << " unique BST trees can be constructed "
                    << "using nodes 1 - " << n << endl;
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
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
