// System headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

// Local includes
#include "targetSum.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

// Statics, globals, typedefs

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
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
printVecOfVec(const vector<vector<int> >& vOfV) {
    cout << endl;
    for (vector<int>::size_type i = 0; i != vOfV.size(); ++i) {
        const vector<int>& v = vOfV[i];
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

void
testFn() {
    cout << "Enter target sum : ";
    int s;
    cin >> s;
    cout << endl << "Enter input vector : ";
    vector<int> v;
    readVec(v);
    cout << "Input vector is : ";
    printVec(v);

    try {
        vector<vector<int> > vV = QuadrapletsAddingUptoTarget::find(v, s);
        cout << "Quadraplets adding upto " << s << " are : ";
        printVecOfVec(vV);
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
