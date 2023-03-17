// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "findInsertLocationInSortedArray.h"

// Using declaration
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::domain_error;

// Statics, globals, typedefs

void
readInputVec(vector<int>& v) {
    v.clear();
    cout << "Enter vector elements : " << endl;
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
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
    try {
        vector<int> v;
        readInputVec(v);
        cout << "Read input vector is : ";
        printVec(v);

        sort(v.begin(), v.end());

        int key;
        cout << "Enter the key whose location is to be searched for : ";
        cin >> key;

        vector<int>::size_type iPos = findInsertPosition(v, key);
        cout << "Key " << key << " to be inserted/located at index " <<
            iPos << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    testFn();
    return 0;
}

