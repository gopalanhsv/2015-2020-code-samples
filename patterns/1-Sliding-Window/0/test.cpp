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
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;
using std::domain_error;
using std::vector;
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

template<typename T>
void
printVec(const vector<T>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

unsigned
readNum(const string& s) {
    unsigned n;
    while (1) {
        cout << s;
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again!!!" << endl;
    }
    return n;
}

void
test() {
    cout << "Enter input array : ";
    vector<int> v;
    readVec(v);
    cout << endl << "Input array is : ";
    printVec(v);

    unsigned k = readNum("Enter subarray size : ");

    try {
        vector<double> av =
            Array::avgOfContiguousSubArraysBruteForce(v, k);
        cout << "Brute force avg of contiguous subarrays of size "
            << k << " is : ";
        printVec(av);

        av.clear();
        av = Array::avgOfContiguousSubArraysSlidingWindow(v, k);
        cout << "Sliding window avg of contiguous subarrays of size "
            << k << " is : ";
        printVec(av);

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
