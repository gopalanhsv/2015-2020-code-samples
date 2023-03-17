// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::domain_error;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
    cin.ignore(10000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
test() {
    cout << "Enter input array : ";
    vector<int> v;
    readVec(v);
    cout << "Sorted input array is : ";
    sort(v.begin(), v.end());
    printVec(v);

    int key;
    while (true) {
        cout << "Enter value of key (for finding n "
            << "closest elements to key) : ";
        if (cin >> key) {
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << endl << "Try again!" << endl;
    }

    int n;
    while (true) {
        cout << "Enter value of n (for finding n "
            << "closest elements to key) : ";
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << endl << "Try again!" << endl;
    }

    try {
        //vector<int> ncv = Array::nClosestNumbersToKey(v, key, n);
        vector<int> ncv =
            Array::nClosestNumbersToKeyTwoPointerMethod(v, key, n);
        cout << n << " closest elements to key " << key << " are : ";
        printVec(ncv);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    test();
    return 0;
}
