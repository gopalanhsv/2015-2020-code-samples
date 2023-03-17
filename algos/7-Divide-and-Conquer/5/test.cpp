// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "minLinesToCollectAllCoins.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

// Statics, typedefs and globals

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
    cout << "Enter coin heights for each column : ";
    readVec(v);
    cout << endl << "Coin heights for each column are : ";
    printVec(v);
    try {
        int ml = minLinesToCollectAllCoins(v);
        cout << "Min lines needed to collect all coins is : " << ml << endl;
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
