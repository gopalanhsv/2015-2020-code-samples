// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

// Local includes
#include "missingNumbers.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, globals, typedefs

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void
readVec(vector<int>& v) {
    v.clear();
    cout << "Enter input vector : ";
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
test() {
    try {
        vector<int> v;
        readVec(v);
        cout << "Input vector is : ";
        printVec(v);
        vector<int> mnv = MultiMissingNumbers::findAllMissingNums(v);
        cout << "Missing Numbers are : ";
        printVec(mnv);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
