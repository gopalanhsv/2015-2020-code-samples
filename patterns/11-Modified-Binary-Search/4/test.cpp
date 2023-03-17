// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

// Local includes
#include "array.h"

// Using declarations
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
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
    cout << "Enter input array of ints : ";
    vector<int> v;
    readVec(v);
    sort(v.begin(), v.end());
    cout << "Input array of ints in ascending order is : ";
    printVec(v);
    while (true) {
        cout << endl << "Enter key whose range is to "
            << "searched for in input array : ";
        int k;
        if (cin >> k) {
            try {
                pair<long, long> nr = Array::keyRange(v, k);
                cout << "Range of key " << k << " in sorted input array is "
                    << "[ " << nr.first << ", " << nr.second << "]" << endl;
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
