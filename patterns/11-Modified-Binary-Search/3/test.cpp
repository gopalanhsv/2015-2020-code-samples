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
readVec(vector<char>& v) {
    v.clear();
    copy(istream_iterator<char>(cin), istream_iterator<char>(),
        back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

void
printVec(const vector<char>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
}

void
test() {
    cout << "Enter input array of chars : ";
    vector<char> v;
    readVec(v);
    sort(v.begin(), v.end());
    cout << "Input array of chars in ascending order is : ";
    printVec(v);
    while (true) {
        cout << endl << "Enter key whose next letter is to "
            << "searched for in input array : ";
        char k;
        if (cin >> k) {
            try {
                char nl = Array::nextLetter(v, k);
                cout << "Next letter of key " << k
                    << " in sorted input array is " << nl << endl;
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
