// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

unsigned
Array::maxSumOfContiguousSubarrays(const vector<int>& v,
    vector<int>::size_type subArrSz) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == subArrSz) {
        throw domain_error("Error! Invalid subarray size!");
    }

    int winSum = 0;
    int maxWinSum = 0;
    // Keep track of contiguous array using sliding window 
    // with elements in range [winStartIdx, winEndIdx]
    vecSzT winStartIdx = 0;
    for (vecSzT winEndIdx = 0; winEndIdx != v.size(); ++winEndIdx) {
        // Slide end of window and add new element
        winSum += v[winEndIdx];
        // Till the contiguous subarray formed by sliding window has
        // at least requisite number of entries, no need to slide the
        // start of window ahead
        if (winEndIdx >= (subArrSz - 1)) {
            // Track max window sum seen so far
            maxWinSum = max(maxWinSum, winSum);
            // Slide start of window one element ahead (and adjust window sum)
            winSum -= v[winStartIdx];
            ++winStartIdx;
        }
    }

    return maxWinSum;
}
