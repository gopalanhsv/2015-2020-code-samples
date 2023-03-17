// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "areDisjointSets.h"

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
    vector<int> s1, s2;
    cout << "Enter set s1: ";
    readVec(s1);
    cout << endl << "Enter set s2: ";
    readVec(s2);
    cout << "Set s1";
    printVec(s1);
    cout << "Set s2";
    printVec(s2);

    try {
        bool b = areDisjointSets(s1, s2);
        cout << "s1 and s2 are " << (b ? "" : "not ") << "disjoint" << endl;
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
