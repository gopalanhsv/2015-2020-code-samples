// System headers
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "tripletSumCloseToTarget.h"

// Statics, typedefs, globals

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::sort;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

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
testFn() {
    cout << "Enter target sum : ";
    int t;
    while (!(cin >> t));
    vector<int> v;
    cout << "Enter input vector : ";
    readVec(v);
    cout << "Input vector is : ";
    printVec(v);
    try {
        v = TripletSumCloseToTarget::searchTriplet(v, t);
        cout << "Triplets close to target in input vector are : ";
        printVec(v);
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
