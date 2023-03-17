// System headers
#include <iostream>
#include <vector>
#include <stdexcept>

// Local includes
#include "median.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream;

template<typename T>
istream&
readVec(istream& in, vector<T>& v) {
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

int
main() {
    vector<int> v1;
    readVec(cin, v1);
    try {
        int m = median(v1);
        cout << "Median(int) = " << m << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    vector<double> v2;
    readVec(cin, v2);
    try {
        double m = median(v2);
        cout << "Median(double) = " << m << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    vector<unsigned int> v3;
    readVec(cin, v3);
    try {
        unsigned int m = median(v3);
        cout << "Median(unsigned int) = " << m << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    vector<short> v4;
    readVec(cin, v4);
    try {
        short m = median(v4);
        cout << "Median(short) = " << m << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }
}

