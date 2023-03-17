// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

// Using declarations
using std::vector;
using std::domain_error;
using std::max;
using std::min;
using std::numeric_limits;

// Local includes
#include "minimumWindowSort.h"

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vecSzT
MinWindowSort::minSubarrayLen(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Find indices [lo, hi] bounding the unsorted subarray of vector

    // Index of first element from start of vector which is out
    // of sorted order
    vecSzT lo = 0;
    while (lo < v.size() - 1 && v[lo] <= v[lo + 1]) {
        ++lo;
    }

    // Index of first element from end of vector which is out
    // of sorted order
    vecSzT hi = v.size() - 1;
    while (hi > 0 && v[hi - 1] <= v[hi]) {
        --hi;
    }

    if (lo > hi) {
        return 0;
    }

    // Find the max and min elements of unsorted subarray of vector
    int maxElem = numeric_limits<int>::min();
    int minElem = numeric_limits<int>::max();
    for (vecSzT k = lo; k <= hi; ++k) {
        maxElem = max(maxElem, v[k]);
        minElem = min(minElem, v[k]);
    }

    // Extend the subarray to the beginning of the vector to include
    // vector elements bigger than the min subarray element
    while (lo > 0 && v[lo - 1] > minElem) {
        --lo;
    }

    // Extend the subarray to the end of the vector to include
    // vector elements smaller than the max subarray element
    while (hi < v.size() - 1 && v[hi + 1] < maxElem) {
        ++hi;
    }

    // So we need to sort subarray [lo, hi] of vector to 
    // completely have all elements in sorted order.
    // return the number of elements in this subarray
    return hi - lo + 1;
}
