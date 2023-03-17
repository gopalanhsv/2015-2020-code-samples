// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "partitionIntegerSet.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
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
    vector<int> v;
    cout << "Enter array of nos : ";
    readVec(v);
    cout << endl << "Input array is :";
    printVec(v);
    try {
        bool partitionPossible = twoEqualSumSubsetRecursive(v);
        cout << endl << "Partition " <<
            ( (partitionPossible) ? "possible" : "impossible" ) <<
            " via recursive method" << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        bool partitionPossible = twoEqualSumSubsetsUsingDPMemoization(v);
        cout << endl << "Partition " <<
            ( (partitionPossible) ? "possible" : "impossible" ) <<
            " via recursive dp memoization" << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        bool partitionPossible = twoEqualSumSubsetsUsingDPTabulation(v);
        cout << endl << "Partition " <<
            ( (partitionPossible) ? "possible" : "impossible" ) <<
            " via dp tabulation" << endl;
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
