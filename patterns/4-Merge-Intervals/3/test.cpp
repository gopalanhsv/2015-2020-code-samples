// System headers
#include <vector>
#include <stdexcept>
#include <iostream>

// Local includes
#include "intervalsIntersection.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;

// Statics, typedefs, globals

void
readVec(vector<Interval>& v) {
    v.clear();
    cout << "Enter num of intervals : ";
    int n;
    while (!(cin >> n));
    while (n--) {
        long s, e;
        cout << endl << "Enter start time : ";
        while (!(cin >> s));
        cout << endl << "Enter end time : ";
        while (!(cin >> e));

        v.push_back(Interval(s, e));
    }
}

void
printVec(const vector<Interval>& v) {
    cout << endl;
    for (vector<Interval>::size_type i = 0; i != v.size(); ++i) {
        cout << "[ " << v[i].start() << ", " << v[i].end() << "], ";
    }
    cout << endl;
}

void
testFn() {
    try {
        vector<Interval> v1, v2;
        readVec(v1);
        readVec(v2);
        cout << "Input Intervals #1 are : ";
        printVec(v1);
        cout << "Input Intervals #2 are : ";
        printVec(v2);

        v1 = Intervals::findIntersectionSet(v1, v2);
        cout << "Intersection Interval list of #1 & #2 is : ";
        printVec(v1);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
