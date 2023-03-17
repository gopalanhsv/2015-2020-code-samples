// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <utility>

// Local includes
#include "pairsWithTargetSum.h"

// Statics, typedefs, globals

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::pair;
using std::vector;
using std::domain_error;
using std::runtime_error;

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
    vector<int> v;
    cout << "Enter input array : ";
    readVec(v);
    cout << "Input array is : ";
    printVec(v);

    int ts;
    cout << "Enter target sum to be found : ";
    while (!(cin >> ts));

    try {
        pair<int, int> p = PairsWithTargetSum::findPairsTwoPtrs(v, ts);
        cout << "Pairs with target sum of " << ts << " via two ptr are ("
            << p.first << ", " << p.second << ")" << endl;
    } catch (domain_error& e) {
        throw e;
    } catch (runtime_error& e) {
        throw e;
    }

    try {
        pair<int, int> p = PairsWithTargetSum::findPairsHashing(v, ts);
        cout << "Pairs with target sum of " << ts << " via hashing are ("
            << p.first << ", " << p.second << ")" << endl;
    } catch (domain_error& e) {
        throw e;
    } catch (runtime_error& e) {
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
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
}
