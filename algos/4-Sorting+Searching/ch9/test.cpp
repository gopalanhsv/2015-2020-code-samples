// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <string>

// Local includes
#include "searchStringInSparseArray.h"

// Using declaration
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::domain_error;

// Statics, globals, typedefs

void
readInputVec(vector<string>& v) {
    v.clear();
    cout << "Enter vector elements : " << endl;
    string x;
    while (getline(cin, x)) {
        v.push_back(x);
    }
    cin.clear();
}

void
printVec(const vector<string>& v) {
    cout << endl << "\"";
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << "\"" << endl;
}

void
testFn() {
    try {
        vector<string> v;
        readInputVec(v);
        cout << "Read input vector is : ";
        printVec(v);

        string key;
        cout << "Enter the key whose presence is to be searched for : ";
        cin >> key;

        bool found = searchStringInSparseArray(v, key);
        cout << "Key " << key <<
            ((found) ? " " : " not ") << "found!" << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    testFn();
    return 0;
}

