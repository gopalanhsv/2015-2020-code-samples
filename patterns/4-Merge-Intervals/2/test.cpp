// System headers
#include <vector>
#include <stdexcept>
#include <iostream>

// Local includes
#include "insertInterval.h"

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
        cout << "[ " << v[i].startTime() << ", " << v[i].endTime() << "], ";
    }
    cout << endl;
}

void
testFn() {
    try {
        vector<Interval> v;
        readVec(v);
        cout << "Input Intervals are : ";
        printVec(v);

        long s, e;
        cout << "Enter start time of new interval :";
        while (!(cin >> s));
        cout << "Enter end time of new interval :";
        while (!(cin >> e));
        Interval ni(s, e);

        v = InsertInterval::insert(v, ni);
        cout << "Interval list after insertion is : ";
        printVec(v);
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
