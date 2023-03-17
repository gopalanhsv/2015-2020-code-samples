// System headers
#include <iostream>
#include <vector>
#include <stdexcept>

// Local includes
#include "median.h"

// Using declarations
using std::vector;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Typedefs & globals

template<typename T>
istream&
readVec(istream& in, vector<T>& v) {
    if (!in) {
        throw domain_error("Error! Errored i/p stream! Exiting...!");
    }

    v.clear();
    T x;
    while (in >> x) {
        v.push_back(x);
    }
    in.clear();
    return in;
}

template<typename T>
void
readAndComputeMedian() {
    vector<T> v;
    try {
        readVec(cin, v);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }

    try {
        T m = median(v.begin(), v.end());
        cout << "Median is : " << m << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    try {
        readAndComputeMedian<int>();
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    try {
        readAndComputeMedian<double>();
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
