// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

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
    vector<int> v;
    cout << "Enter input array : ";
    readVec(v);
    cout << "Input array is : ";
    printVec(v);

    while (true) {
        cout << "Enter value of k (k top frequency elements) : ";
        int k;
        if (cin >> k) {
            try {
                vector<int> topkv = Array::topKFrequentNumbers(v, k);
                cout << "Top " << k << " frequent elements in input are : ";
                printVec(topkv);
            } catch (domain_error& e) {
                throw e;
            }
            break;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
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
