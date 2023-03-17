// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "duplicateNumber.h"

// Using declarations
using std::vector;
using std::swap;
using std::domain_error;
using std::runtime_error;

// Statics, typedefs, globals

// v contains n+1 numbers in range [1, n].
// One of the numbers is duplicated
int
DupNumber::findDuplicateNum(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;

    // Iterate over all the vector elements
    vecSzT i = 0;
    while (i != v.size()) {
        // Determine correct sorted location for element v[i]
        vecSzT correctIdx = v[i] - 1;
        // Check if element at index 'i' is at its correct location
        if (i != correctIdx) {
            // Element v[i] not at its correct sorted location
            // Swap element at 'correctIdx' with element at 'i', so
            // that v[i] moves to its correct sorted location
            // If elements being swapped have identical vals, duplicate
            // element found
            if (v[i] == v[correctIdx]) {
                return v[i];
            }
            swap(v[i], v[correctIdx]);
        } else {
            // Element v[i] is at its correct sorted location, advance
            // to next vector element
            ++i;
        }
    }
    throw runtime_error("Error! No duplicate nos!");
}
