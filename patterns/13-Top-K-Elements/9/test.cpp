// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>
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

// Statics, globals, typedefs

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
    cout << "Input array is : ";
    printVec(v);

    while (true) {
        cout << "Enter num elements to be removed : ";
        unsigned int nr;
        if (cin >> nr) {
            try {
                unsigned int m = Array::maxDistinctElementsPostRemoval(v, nr);
                cout << m << " distinct elements after removing "
                    << nr << " from input array" << endl;
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
