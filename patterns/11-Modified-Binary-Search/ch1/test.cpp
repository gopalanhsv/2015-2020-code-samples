// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
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
    cout << "Enter bitonic input array of ints : ";
    vector<int> v;
    readVec(v);
    cout << "Bitonic input array of ints is : ";
    printVec(v);
    while (true) {
        cout << "Enter key to searched for in bitonic array : ";
        int k;
        if (cin >> k) {
            try {
                long pos = BitonicArray::search(v, k);
                cout << endl;
                cout << "Element " << k << " in input bitonic array ";
                if (-1 == pos) {
                    cout << "is not present" << endl;
                } else {
                    cout << "is at index " << pos << endl;
                }
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
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
