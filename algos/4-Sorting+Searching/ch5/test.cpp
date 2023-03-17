// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "findDuplicates.h"

// Using declaration
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::domain_error;

// Statics, globals, typedefs

void
readInputVec(vector<int>& v) {
    v.clear();
    cout << "Enter vector elements : " << endl;
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testFn() {
    vector<int> v, dups;
    readInputVec(v);
    cout << "Read input vector is : ";
    printVec(v);

    try {
        dups = findDuplicates(v);
        cout << "Duplicates in the read vector are : ";
        printVec(dups);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    testFn();
    return 0;
}

