// System headers
#include <vector>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "policeThief.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::runtime_error;
using std::back_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::vector;

// Statics, typedefs and globals

void
readVec(vector<char>& v) {
    v.clear();
    char c;
    while (cin >> c) {
        if (c != 'T' && c != 'P') {
            cout << "Vector entry has to be either P or T" << endl;
            continue;
        }
        v.push_back(c);
    }
    cin.clear();
}

void
printVec(const vector<char>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<char>(cout, ", "));
    cout << endl;
}

void
testFn() {
    vector<char> v;
    cout << "Enter police thief vector "
        "[P at police location, T at thief location] :";
    readVec(v);

    cout << "Police thief location vector : ";
    printVec(v);

    int md;
    cout << "Enter max allowable distance for policeman to catch thief : ";
    while (!(cin >> md));

    try {
        //int mt = maxThievesWhoCanBeCaughtByPoliceBruteForce(v, md);
        int mt = maxThievesWhoCanBeCaughtByPoliceGreedy(v, md);
        cout << "Max # thieves who can be caught is : " << mt << endl;
    } catch (domain_error& e) {
        throw e;
    } catch (runtime_error& e) {
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
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
