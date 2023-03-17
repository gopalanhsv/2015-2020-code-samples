// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

// Local includes
#include "dutchNationalFlag.h"

// Statics, typedefs, globals

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

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int
test() {
    cout << "Enter input vector : ";
    vector<int> v;
    readVec(v);
    cout << "Input vector is : ";
    printVec(v);

    try {
        DutchNationalFlag::sort(v);
        cout << "Sorted input vector is : ";
        printVec(v);
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
