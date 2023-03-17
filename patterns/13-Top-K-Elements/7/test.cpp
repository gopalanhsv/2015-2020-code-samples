// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

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
    cout << "Input vector is : ";
    printVec(v);

    int k;
    while (true) {
        cout << "Enter value of k(for maintaining Kth "
            << "largest elements seen so far) : ";
        if (cin >> k) {
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << endl << "Try again!" << endl;
    }

    KthLargestElement kln(v, k);
    while (true) {
        int n;
        cout << endl << "Enter number to be added : ";
        if (cin >> n) {
            cout << kln.addElement(n) << " is " << k << "th largest "
                << "number seen after adding " << n << endl;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl << "Incorrect entry! Exiting!" << endl;
            break;
        }
    }
}

int
main() {
    test();
    return 0;
}
