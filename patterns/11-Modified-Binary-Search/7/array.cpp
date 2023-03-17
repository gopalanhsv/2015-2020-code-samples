// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

int
BitonicArray::maximum(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Commence binary search to find the maximum in bitonic array
    typedef vector<int>::size_type vecSzT;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    // Do binary search for array maximum and keep adjusting start
    // and end to reduce search range till they end up at same location.
    // That point would be the bitonic array maximum
    while (startIdx < endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] < v[mid + 1]) {
            // Element at midpoint location is not maximum, max element
            // lies at upper part of search range. Update search range.
            startIdx = mid + 1;
        } else { // v[mid] >= v[mid + 1]
            // Element at midpoint location may be maximum or max element
            // lies at lower part of search range. Update search range.
            endIdx = mid;
        }
    }

    return v[startIdx];
}
