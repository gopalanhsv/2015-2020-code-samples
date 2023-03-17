// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <utility>

// Local includes
#include "findPairs.h"

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
using std::pair;

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
    vector<int> v;
    cout << "Enter vector : ";
    readVec(v);
    cout << "Input vector : ";
    printVec(v);

    try {
        vector<pair<int, int> > vp = findPairsWithSameSum(v);
        if (vp.empty()) {
            cout << "Pairs with same sum not found in the vector" << endl;
        } else {
            cout << "Pairs with same sum are : "
                << "(" << vp[0].first << ", " << vp[0].second << "), "
                << "(" << vp[1].first << ", " << vp[1].second << ")" << endl;
        }
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
