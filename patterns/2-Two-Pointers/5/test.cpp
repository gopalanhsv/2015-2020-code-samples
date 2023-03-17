// System headers
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "tripletsWithSmallerSum.h"

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
printVecOfVec(const vector<vector<int> >& vOfV) {
    cout << endl;
    for (auto v : vOfV) {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    cout << endl;
}

void
testFn() {
    vector<int> v;
    cout << "Enter input vector : ";
    readVec(v);
    cout << "Input vector is : ";
    printVec(v);

    int sum;
    cout << "Enter target sum : ";
    while (!(cin >> sum));
    try {
        vector<vector<int> > vV;
        vV = TripletsWithLesserSum::searchTriplets(v, sum);
        cout << vV.size() << endl;
        cout << "Triplets adding to lesser that " << sum
            << " in input vector are : ";
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
