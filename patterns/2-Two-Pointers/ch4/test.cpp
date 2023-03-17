// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>

// Local includes
#include "maxWaterVol.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
test() {
    vector<int> v;
    cout << "Enter building heights : ";
    readVec(v);
    cout << "Heights vector is : ";
    printVec(v);

    try {
        unsigned long mv = MaxWaterVolume::compute(v);
        cout << "Max volume of water which can be stored "
            << "between building is : " << mv << endl;
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
