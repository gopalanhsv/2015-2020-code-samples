// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <string>

// Local includes
#include "traceJourneyPath.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::string;

// Statics, globals, typedefs

void
readVec(vector<pair<string, string> >& vp) {
    vp.clear();
    cout << "Enter number of src/dst pairs : ";
    int n;
    while (!(cin >> n));
    while (n--) {
        string s, d;
        cout << endl << "Enter source : ";
        while (!(cin >> s));
        cout << endl << "Enter destination : ";
        while (!(cin >> d));
        vp.push_back(make_pair(s, d));
    }
    cin.clear();
}

void
printVec(const vector<pair<string, string> >& vp) {
    cout << endl;
    typedef vector<pair<string, string> >::size_type vecSzT;
    for (vecSzT i = 0; i != vp.size(); ++i) {
        cout << "(" << vp[i].first << ", " << vp[i].second << "), ";
    }
    cout << endl;
}

void
testFn() {
    vector<pair<string, string> > vp;
    cout << "Enter input array of src/dst pairs : " << endl;
    readVec(vp);
    cout << endl << "Input array of src/dst pairs : ";
    printVec(vp);
    try {
        string p = tracePath(vp);
        if (p.empty()) {
            cout << "No path" << endl;
        } else {
            cout << "Journey path is : " << p << endl;
        }
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
