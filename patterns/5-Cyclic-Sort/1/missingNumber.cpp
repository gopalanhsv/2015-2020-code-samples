// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "missingNumber.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, globals, typedefs

// Vector has elements in range [0, v.size()], but only
// v.size() elements present (1 number missing)
int
MissingNumber::findMissingNum(vector<int> v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    typedef vector<int>::size_type vecSzT;

    // Iterate over all indices/elements of given vector
    // and sort them to correct location using cyclic sort
    vecSzT i = 0;
    while (i != v.size()) {
        // Element value[i] gives sorted location
        vecSzT correctIdx = v[i];
        // If the element at i is not at its correct sorted location
        // (Check for correctIdx is done as n len vec may be holding
        // which should ideally contain 0 to n-1 may end up holding
        // value n 
        if (correctIdx < v.size() && i != correctIdx) {
            // If the current element at i is not at its correct sorted location,
            // move the element to its correct sorted location by swapping
            // the elements at index i with correctIdx
            swap(v[i], v[correctIdx]);
        } else {
            // Element at index 'i' is at its correct sorted
            // location. Move to next element
            ++i;
        }
    }

    // Scan vector and find element which is not in its sorted location
    // That would would be the missing number
    for (vecSzT i = 0; i != v.size(); ++i) {
        if (i != v[i]) {
            return i;
        }
    }
    // If all elements are in proper sorted location, last element is the
    // one missing
    return v.size();
}
