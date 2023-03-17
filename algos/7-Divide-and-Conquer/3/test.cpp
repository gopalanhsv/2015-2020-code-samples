// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>

// Local includes
#include "maxSubarraySum.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::back_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testFn() {
    vector<int> v;
    while (true) {
        cout << endl << "Enter input array : ";
        readVec(v);
        cout << endl << "Input Vec : ";
        printVec(v);
        try {
            int ms = maxSumOfSubArraysBruteForce(v);
            cout << "Max contiguous sum in vec via brute force is "
                << ms  << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            int ms = maxSumOfSubArraysDivAndConquer(v);
            cout << "Max contiguous sum in vec via divide and conquer is "
                << ms  << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            int ms = maxSumOfSubArraysDP(v);
            cout << "Max contiguous sum in vec via Kadane DP algo is "
                << ms  << endl;
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
