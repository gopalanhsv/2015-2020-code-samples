// System headers
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
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
    cin.ignore(1000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

unsigned long
readNum(const string& s) {
    unsigned long k;
    while (true) {
        cout << "Enter " << s << " (for sum between k1&k2 smallest elems) : ";
        if (cin >> k) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again!" << endl;
    }
    return k;
}

void
test() {
    cout << "Enter input vector : ";
    vector<int> v;
    readVec(v);
    cout << "Input vector is : ";
    printVec(v);

    unsigned long k1 = readNum("k1");
    unsigned long k2 = readNum("k2");
    try {
        unsigned long s =
            Array::elementsSumBetweenK1AndK2SmallestElems(v, k1, k2);
        cout << "Sum of elements between " << k1 << "th and " << k2
            << "th smallest elements in input array is : " << s << endl; 
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
