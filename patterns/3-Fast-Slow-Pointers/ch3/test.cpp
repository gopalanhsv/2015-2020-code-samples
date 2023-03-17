// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "circularArray.h"

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

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testFn() {
    vector<int> v;
    cout << "Enter input array : ";
    readVec(v);
    cout << "Input array is : ";
    printVec(v);

    try {
        bool b = CircularArray::hasCycle(v);
        cout << "Input circular array " 
            << (b ? "has" : "doesn't have") << " cycle!" << endl;
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
