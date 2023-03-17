// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

// Local includes
#include "findKLargestElems.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void
testFn() {
    vector<int> v;
    cout << "Enter input vector : ";
    readVec(v);
    cout << endl << "Input vector is : ";
    printVec(v);
    cout << "Enter value of k : ";
    int k;
    while (!(cin >> k));

    try {
        vector<int> maxKVec = kLargestElements(v, k);
        cout << endl << k << " largest elements of input vector are : ";
        printVec(maxKVec);
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
