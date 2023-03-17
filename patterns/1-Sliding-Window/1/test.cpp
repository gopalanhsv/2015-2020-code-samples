// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

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
using std::string;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

unsigned
readNum(const std::string& s) {
    unsigned n;
    while (1) {
        cout << s;
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again!!!" << endl;
    }
    return n;
}

void
test() {
    cout << "Enter input array : ";
    vector<int> v;
    readVec(v);

    unsigned sz = readNum("Enter subarray size : ");
    try {
        unsigned sum = Array::maxSumOfContiguousSubarrays(v, sz);
        cout << "Max sum of a contiguous subarray of size " << sz
            << " in given array is : " << sum << endl;
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
