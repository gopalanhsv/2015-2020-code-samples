// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <string>

// Local includes
#include "symmetricPairs.h"

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
readVec(vector<pair<int, int> >& vp) {
    vp.clear();
    cout << "Enter number of pairs : ";
    int n;
    while (!(cin >> n));
    while (n--) {
        int f, s;
        cout << endl << "Enter 1st member : ";
        while (!(cin >> f));
        cout << endl << "Enter 2nd member : ";
        while (!(cin >> s));
        vp.push_back(make_pair(f, s));
    }
    cin.clear();
}

void
printVec(const vector<pair<int, int> >& vp) {
    cout << endl;
    typedef vector<pair<int, int> >::size_type vecSzT;
    for (vecSzT i = 0; i != vp.size(); ++i) {
        cout << "(" << vp[i].first << ", " << vp[i].second << "), ";
    }
    cout << endl;
}

void
testFn() {
    vector<pair<int, int> > vp;
    cout << "Enter input array of pairs : " << endl;
    readVec(vp);
    cout << endl << "Input array of pairs : ";
    printVec(vp);
    try {
        string sp = symmetricPairsInVec(vp);
        if (sp.empty()) {
            cout << "No symmetric pairs" << endl;
        } else {
            cout << "Symmetric pairs are " << sp << endl;
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
