// System includes
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Local includes
#include "array.h"

// Using dcelarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

template<typename T>
void
readVec(vector<T>& v) {
    v.clear();
    copy(istream_iterator<T>(cin), istream_iterator<T>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

template<typename T>
void
printVec(const vector<T>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

template<typename T>
T
readInput(const string& s) {
    T x;
    while (1) {
        cout << endl << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again!!!";
    }
    return x;
}

void
test() {
    vector<int> v;
    cout << "Enter input array of 0s/1s : ";
    readVec<int>(v);
    cout << endl << "Input array of 0s/1s is : ";
    printVec<int>(v);

    unsigned k =
        readInput<unsigned>("Enter max num of 1s which can be replaced in array: ");

    try {
        unsigned l = Array::longestSubarrayWithAll1sPostReplacement(v, k);
        cout << "Longest subarray with all ones "
            << " is of len " << l
            << " after replacing a maximum of " << k << " zeros " << endl;
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
