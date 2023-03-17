// System headers
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

// Local includes
#include "pascalTriangle.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::domain_error;

// Statics, typedefs, globals

void
printVec(const vector<unsigned int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;
}

void
testFn() {
    while (1) {
        cout << "Enter Pascal Triangle line # : ";
        unsigned int l;
        while (!(cin >> l));
        try {
            vector<unsigned int> ptv = pascalTriangleIterative(l);
            printVec(ptv);
        } catch (domain_error& e) {
            throw e;
        }
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
