// System headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <utility>

// Local includes
#include "arrays.h"

// Using declarations
using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::sort;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::domain_error;

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
test() {
    unsigned int n;
    while (1) {
        cout << "Enter number of input arrays : ";
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error! Try again!" << endl;
    }

    vector<vector<int> > arraysV;
    while (n--) {
        cout << endl << "Enter elems of array#" << n + 1 << " : " << endl;
        vector<int> v;
        readVec(v);
        sort(v.begin(), v.end());
        arraysV.push_back(v);
        cout << "Sorted input array#" << n + 1;
        printVec(v);
    }

    try {
        pair<int, int> r = Array::smallestRange(arraysV);
        cout << "Smallest range of elements encompassing at least one "
            << "element from each of input arrays are (" << r.first
            << ", " << r.second << ")" << endl;
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
