// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "activityScheduling.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;
using std::back_inserter;
using std::copy;
using std::string;

// Statics, typedefs, globals

void
readInput(vector<ActivityInfoT>& v) {
    v.clear();
    int n;
    cout << "Enter number of activities : ";
    while (!(cin >> n));

    int id = 0;
    while (n--) {
        ActivityInfoT ai;
        ai.id = id++;
        cout << "Enter start time : ";
        while (!(cin >> ai.start));
        cout << "Enter finish time : ";
        while (!(cin >> ai.end));

        v.push_back(ai);
    }

    cin.clear();
}

void
printVec(const vector<ActivityInfoT>& v) {
    cout << endl;
    for (vector<ActivityInfoT>::size_type i = 0; i != v.size(); ++i) {
        const ActivityInfoT& ai = v[i];
        cout << "Activity id : " << ai.id << ", start : "
            << ai.start << ", end : " << ai.end << endl;
    }
    cout << endl;
}

void
printVec(const vector<int>& v, const string& sep) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, sep.c_str()));
    cout << endl;
}

void
testFn() {
    vector<ActivityInfoT> aiv;
    readInput(aiv);
    printVec(aiv);

    try {
        vector<int> ma = determineMaxActivitiesBruteForce(aiv);
        cout << "Max activities size via brute force = " << ma.size() << endl;
        cout << "Max activities via brute force are ordered as ";
        printVec(ma, ",");
    } catch (domain_error& e) {
        throw e;
    }

    try {
        vector<int> ma = determineMaxActivitiesGreedy(aiv);
        cout << "Max activities size via greedy approach = " << ma.size() << endl;
        cout << "Max activities via greedy approach are ordered as ";
        printVec(ma, ",");
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
