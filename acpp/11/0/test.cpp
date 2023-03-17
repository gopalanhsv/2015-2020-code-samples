// System headers
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "Vec.h"

// Using declarations
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::domain_error;
using std::ostream_iterator;
using std::copy;

// Typedefs

template<typename T>
istream&
readVec(istream& in, Vec<T>& v) {
    if (in) {
        v.clear();
        T x;
        while (cin >> x) {
            v.push_back(x);
        }
        in.clear();
    }
    return in;
}

template<typename T>
void
displayVec(ostream& os, const Vec<T>& v) {
    if (!os) {
        throw domain_error("Error! Invalip o/p stream! Exiting...!");
    }

    if (v.empty()) {
        throw domain_error("Error! Empty Vec to display! Exiting...!");
    }

    os << "Display Vec<T>" << endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    os << endl;
}

template<typename T>
void
testVec() {
    Vec<T> v;
    readVec(cin, v);
    try {
        displayVec(cout, v);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    testVec<int>();
    testVec<string>();
    testVec<double>();

    return 0;
}
