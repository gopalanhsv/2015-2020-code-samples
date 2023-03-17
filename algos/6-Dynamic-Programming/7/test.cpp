// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "coinChange.h"

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
    cout << "Enter array of coin denominations : ";
    readVec(v);
    cout << endl << "Input array is :";
    printVec(v);
    cout << "Enter amount to be changed : ";
    long amt;
    while (!(cin >> amt));

    try {
        long nWays = numWaysToChangeCoinsBruteForce(v, amt);
        cout << endl << nWays << " ways to change coins " <<
            "via recursive method" << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        long nWays = numWaysToChangeCoinsDPMemoization(v, amt);
        cout << endl << nWays << " ways to change coins " <<
            "via recursive dp memoization" << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        long nWays = numWaysToChangeCoinsDPTabulation(v, amt);
        cout << endl << nWays << " ways to change coins " <<
            "via dp tabulation" << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        long nWays = numWaysToChangeCoinsDPTabulationOptimized(v, amt);
        cout << endl << nWays << " ways to change coins " <<
            "via dp tabulation optimized" << endl;
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
