// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "number.h"

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
using std::pair;

// Statics, typedefs, globals

void
readVec(vector<unsigned int>& v) {
    v.clear();
    cout << "Enter input vector : ";
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
}

void
printVec(const vector<unsigned int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testFn() {
    vector<unsigned int> v;
    readVec(v);
    cout << "Input vector is : ";
    printVec(v);

    try {
        pair<unsigned int, unsigned int> np =
            Number::findTwoUniqueNumbers(v);
        cout << "Two missing unique elements in vector are " <<
            np.first << ", " << np.second << endl;
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
