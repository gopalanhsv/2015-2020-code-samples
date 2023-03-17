// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "cyclicSort.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, globals, typedefs

void
CyclicSort::sort(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    typedef vector<int>::size_type vecSzT;

    // Iterate over all indices/elements of given vector
    vecSzT i = 0;
    while (i != v.size()) {
        // Element value[i] - 1 gives sorted location
        vecSzT correctIdx = v[i] - 1;
        if (i != correctIdx) {
            // If the current element at i is not at its correct sorted location,
            // move the element to its correct sorted location by swapping
            // the elements
            swap(v[i], v[correctIdx]);
        } else {
            // Element at index 'i' is at its correct sorted
            // location. Move to next element
            ++i;
        }
    }
}
