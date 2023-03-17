// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "duplicateNumbers.h"

// Using declarations
using std::vector;
using std::swap;
using std::domain_error;
using std::runtime_error;

// Statics, typedefs, globals

// v contains n numbers in range [1, n].
// Several of the numbers are duplicated
vector<int>
AllDupNumbers::findDuplicateNums(vector<int> v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;

    // Iterate over all the vector elements. Sort them
    // to their appropriate locations using cyclic sort
    vecSzT i = 0;
    while (i != v.size()) {
        // Determine correct sorted location for element v[i]
        vecSzT correctIdx = v[i] - 1;
        // Check if element at index 'i' is at its correct location
        if (v[i] != v[correctIdx]) {
            // Element v[i] not at its correct sorted location
            // Swap element at 'correctIdx' with element at 'i', so
            // that v[i] moves to its correct sorted location
            swap(v[i], v[correctIdx]);
        } else {
            // Element v[i] is at its correct sorted location, advance
            // to next vector element
            ++i;
        }
    }

    // Iterate over the entire sorted vector again to determine
    // missing nums/dups
    vector<int> dupV;
    for (vecSzT i = 0; i != v.size(); ++i) {
        if (v[i] != i + 1) {
            dupV.push_back(v[i]);
        }
    }
    if (dupV.empty()) {
        throw runtime_error("Error! No duplicates in vector!");
    }
    return dupV;
}
