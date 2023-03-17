// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cstddef>

// Local includes
#include "median.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::ostream;
using std::domain_error;
using std::copy;
using std::ostream_iterator;

// Typedefs

template<typename T>
istream&
readVec(istream& in, vector<T>& v) {
    if (in) {
        v.clear();
        T x;
        while (in >> x) {
            v.push_back(x);
        }
        in.clear();
    }
    return in;
}

template<typename T>
void
writeVec(ostream& os, const vector<T>& v) {
    if (!os) {
        throw domain_error("Error! Invalid o/p stream! Exiting...!");
    }

    if (v.empty()) {
        throw domain_error("Error! Empty input vector! Exiting...!");
    }

    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    os << endl;
}

template<typename T>
void
testVec() {
    vector<T> v;
    readVec(cin, v);
    T med;
    median(v.begin(), v.end(), med);
    cout << "Median is = " << med << endl;
    cout << "Vector after median computation" << endl;
    writeVec(cout, v);
}

template<typename T>
T*
readArray(istream& in, ostream& os, size_t& n) {
    if (!in)
        return NULL;
    os << "Enter number of elems in array : ";
    in >> n;
    T* arr = new T[n];
    for (size_t i = 0; i != n; ++i) {
        T x;
        if (in >> x) {
            arr[i] = x;
        } else {
            os << "Errored input! Exiting...!" << endl;
            delete[] arr;
            return NULL;
        }
    }
    return arr;
}

template<typename T>
void
writeArray(ostream& os, const T* beg, const T* end) {
    if (!os)
        return;
    cout << "Array contents" << endl;
    copy(beg, end, ostream_iterator<T>(cout, " "));
    cout << endl;
}

template<typename T>
void
testArray() {
    size_t n;
    T *arr = readArray<T>(cin, cout, n);
    if (!arr)
        return;
    cout << n << endl;
    writeArray(cout, arr, arr + n);
    T med;
    median(arr, arr + n, med);
    cout << "Median is = " << med << endl;
    writeArray(cout, arr, arr + n);
    delete[] arr;
}

int
main() {
    testVec<int>();
    testVec<double>();
    testArray<int>();
    testArray<double>();
    return 0;
}
