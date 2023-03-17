// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "isSubset.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void
test() {
    vector<int> v1, v2;
    cout << "Enter vector v1: ";
    readVec(v1);
    cout << endl << "Enter vector v2: ";
    readVec(v2);
    cout << "Vector v1";
    printVec(v1);
    cout << "Vector v2";
    printVec(v2);

    try {
        bool b = is2ndVecSubsetof1st(v1, v2);
        cout << "v2 is " << (b ? "" : "not ") << "a subset of v1" << endl;
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
