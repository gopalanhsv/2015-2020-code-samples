// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "arrays.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::domain_error;
using std::copy;
using std::sort;

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
    unsigned n;
    while (true) {
        cout << endl << "Enter number of lists to be sorted : ";
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try entering again!!!" << endl;
    }

    vector<vector<int> > arraysV;
    while (n--) {
        cout << "Enter elems for array #" << n + 1 << " : ";
        vector<int> v;
        readVec(v);
        sort(v.begin(), v.end());
        arraysV.push_back(v);
        cout << endl << "Sorted elems array #" << n + 1;
        printVec(v);
    }

    unsigned k;
    while (true) {
        cout << endl << "Enter 'k' for kth smallest element : ";
        if (cin >> k) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try entering again!!!" << endl;
    }

    try {
        int s = Arrays::kthSmallestNumAmongstAll(arraysV, k);
        cout << s << " is the " << k << "th smallest element" << endl;
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
