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
using std::copy;
using std::sort;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
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
    cout << "Enter input big array of ints : ";
    vector<int> v;
    readVec(v);
    sort(v.begin(), v.end());
    cout << endl << "Input big array of ints is : ";
    printVec(v);

    BigArrayReader *bga = nullptr;
    try {
        bga = new BigArrayReader(v);
    } catch (...) {
        throw;
    }

    while (true) {
        cout << endl << "Enter key to be searched for : ";
        int k;
        if (cin >> k) {
            try {
                long pos = InfiniteArray::search(bga, k);
                cout << "Key " << k;
                if (pos < 0) {
                    cout << " missing!" << endl;
                } else {
                    cout << " found at index " << pos << endl;
                }
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
