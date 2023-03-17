// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

// Local includes
#include "rope.h"

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
readVec(vector<unsigned int>& v) {
    v.clear();
    copy(istream_iterator<unsigned int>(cin),
        istream_iterator<unsigned int>(), back_inserter(v));
    cin.clear();
    cin.ignore(10000, '\n');
}

void
printVec(const vector<unsigned int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;
}

void
test() {
    vector<unsigned int> v;
    cout << "Enter input array of rope lengths : ";
    readVec(v);
    cout << "Input array is : ";
    printVec(v);

    try {
        unsigned long mc = Rope::connectWithMinCost(v);
        cout << "Minimum cost of connecting ropes is " << mc << endl;
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
