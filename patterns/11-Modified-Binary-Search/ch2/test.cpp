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
using std::domain_error;
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
    cin.ignore(10000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
test(bool dup = false) {
    cout << "Enter input array "
        << ((dup) ? "with duplicates : " : ": ") << endl;
    vector<int> v;
    readVec(v);
    cout << "Input array " << ((dup) ? "with duplicates " : "")
        << "is : " << endl;

    while (true) {
        cout << endl << "Enter key to be searched for : ";
        int k;
        if (cin >> k) {
            try {
                int pos;
                if (dup) {
                    pos = RotatedArray::searchWithDuplicates(v, k);
                } else {
                    pos = RotatedArray::search(v, k);
                }
                cout << endl << "Key " << k;
                if (pos < 0) {
                    cout << " not found!" << endl;
                } else {
                    cout << " is located at " << pos << endl;
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
        test(true);
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
