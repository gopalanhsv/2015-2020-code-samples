// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <algorithm>

// Local includes
#include "groupAnagrams.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::copy;
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;

// Statics, typedefs, globals

void
readInputVec(vector<string>& v) {
    cout << " Enter input vector of strings : ";
    v.clear();
    string x;
    while (getline(cin, x)) {
        v.push_back(x);
    }
    cin.clear();
}

void
printVec(const vector<string>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
}

void
testFn() {
    vector<string> v;
    readInputVec(v);
    printVec(v);
    int n;
    cin >> n;
    try {
        vector<string> anagrams = groupAnagrams(v);
        cout << "Anagram groups from input : " << endl;
        printVec(anagrams);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    testFn();
    return 0;
}
