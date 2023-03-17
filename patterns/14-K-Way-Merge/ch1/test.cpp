// System headers
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "arrays.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::sort;
using std::copy;
using std::pair;
using std::greater;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
printVecPairs(const vector<pair<int, int> >& v) {
    cout << endl;
    for (auto p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void
test() {
    cout << "Enter array#1 elements : ";
    vector<int> v1;
    readVec(v1);
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "Sorted array #1 elements are :";
    printVec(v1);

    cout << endl << "Enter array#2 elements : ";
    vector<int> v2;
    readVec(v2);
    sort(v2.begin(), v2.end(), greater<int>());
    cout << "Sorted array #2 elements are :";
    printVec(v2);

    unsigned long k;
    while (true) {
        cout << "Enter number of greatest sum pairs to find in v1/v2 : ";
        if (cin >> k) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again!!!";
    }

    try {
        vector<pair<int, int> > vp =
            Arrays::findPairsWithLargestSum(v1, v2, k);
        cout << "Largest sum " << k
            << " pairs across given 2 input arrays are :";
        printVecPairs(vp);
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
