// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "subsets.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    cin.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.ignore(10000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
printVecOfVec(const vector<vector<int> >& vOfV) {
    cout << endl;
    for (auto v : vOfV) {
        cout << "[ ";
        for (auto n : v) {
            cout << n << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

void
testFn() {
    vector<int> v;
    cout << "Enter elements whose subsets are to be determined : ";
    readVec(v);
    cout << "Input elements are : ";
    printVec(v);
    try {
        vector<vector<int> > subsetsV =
            Subset::determineSubsetsWithInputDuplicates(v);
        cout << "Subsets of input elements are : ";
        printVecOfVec(subsetsV);
    } catch (domain_error& e) {
        throw e;
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
