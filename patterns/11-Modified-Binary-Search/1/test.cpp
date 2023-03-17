// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::domain_error;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;
using std::sort;

// Statics, tyepdefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
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
    vector<int> av;
    cout << "Enter input array : ";
    readVec(av);
    sort(av.begin(), av.end());
    cout << "Input array in ascending order is : ";
    printVec(av);

    vector<int> dv;
    copy(av.rbegin(), av.rend(), back_inserter(dv));
    cout << "Input array in descending order is : ";
    printVec(dv);

    while (true) {
        cout << "Enter key to be searched for : ";
        int k;
        if (cin >> k) {
            try {
                long long apos =
                    OrderedArray::orderAgnosticBinarySearch(av, k);
                long long dpos =
                    OrderedArray::orderAgnosticBinarySearch(dv, k);
                cout << "Key " << k << " is at index " << apos
                    << " in ascending and at index " << dpos
                    << " in descending!" << endl;
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
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
