// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "mergeSortedArrays.h"

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
readVecOfVecs(vector<vector<int> >& vecArr) {
    cout << "Enter number of sorted arrays : ";
    int n;
    cin >> n;
    while (n--) {
        cout << "Enter input array : ";
        vector<int> v;
        readVec(v);
        sort(v.begin(), v.end());
        vecArr.push_back(v);
    }
}

void
printVecOfVecs(const vector<vector<int> >& vecArr) {
    typedef vector<vector<int> >::size_type vecVecSzT;
    cout << endl << "Array of arrays :";
    for (vecVecSzT i = 0; i != vecArr.size(); ++i) {
        cout << endl;
        const vector<int>& v = vecArr[i];
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    }
    cout << endl;
}

void
testFn() {
    vector<vector<int> > vv;
    readVecOfVecs(vv);

    try {
        vector<int> sv = mergeSortedArraysBruteForce(vv);
        cout << "Shuffled array via brute force :";
        printVec(sv);
    } catch (domain_error& e) {
        throw e;
    }

    try {
        vector<int> sv = mergeSortedArraysDivAndConq(vv);
        cout << "Shuffled array via divide and conquer :";
        printVec(sv);
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
