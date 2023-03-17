// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "findPlatforms.h"

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
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v, const string& sep) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, sep.c_str()));
    cout << endl;
}

void
testFn() {
    vector<int> av, dv;
    cout << "Enter arrival times : ";
    readVec(av);
    cout << "Enter departure times : ";
    readVec(dv);
    cout << "Arrival times are : ";
    printVec(av, " ");
    cout << "Departure times are : ";
    printVec(dv, " ");

    try {
        //int np = computePlatformsNeededUsingBruteForce(av, dv);
        int np = computePlatformsNeededUsingGreedyMethod1(av, dv);
        //int np = computePlatformsNeededUsingGreedyMethod2(av, dv);
        cout << "Num platforms required are " << np << endl;
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
