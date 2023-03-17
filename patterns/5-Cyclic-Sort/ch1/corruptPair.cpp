// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "corruptPair.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::runtime_error;
using std::swap;

// Statics, globals, typedefs

// Vector has v.size() elements in range [1, v.size()], but
// one element is duplicated (and another missing as a result
// of same)
vector<int>
CorruptPair::findCorruptPair(vector<int> v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    typedef vector<int>::size_type vecSzT;

    // Iterate over all elements of given vector
    // and sort them to correct location using cyclic sort
    vecSzT i = 0;
    while (i != v.size()) {
        // Determine correct sorted location of element v[i]
        vecSzT correctIdx = v[i] - 1;
        if (v[i] != v[correctIdx]) {
            // Element at i is not at its correct sorted location,
            // move the element to its correct sorted location by swapping
            // the element at index 'i' with element at 'correctIdx'
            swap(v[i], v[correctIdx]);
        } else {
            // Element at index 'i' is at its correct sorted
            // location. Move to next element
            ++i;
        }
    }

    // Scan vector and find element which is not in its sorted location
    // That would would be the missing number and number at that place
    // would be the duplicate
    for (vecSzT i = 0; i != v.size(); ++i) {
        if (v[i] != i + 1) {
            return vector<int>{v[i], i + 1};
        }
    }

    // Vector has no duplicate/missing nos
    throw runtime_error("Error! No missing/dup number in vector!");
}
