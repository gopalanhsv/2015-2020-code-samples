// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::min;
using std::copy;
using std::back_inserter;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vector<int>
Array::smallestSubarrayWithMinSum(const vector<int>& v, int minSum) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    int winSum = 0;
    vecSzT minWinLen = 0;
    // Ensure that elements of contiguous array in the sliding window
    // [winStartIdx, winEndIdx] always add up to at least minimum sum
    vecSzT winStartIdx = 0;
    vecSzT minStartIdx = 0;
    vecSzT minEndIdx = 0;
    for (vecSzT winEndIdx = 0; winEndIdx != v.size(); ++winEndIdx) {
        // Move the right edge of sliding window one element to right
        // by including element at winEndIdx
        winSum += v[winEndIdx];
        // If the window sum exceeds/equals minimum, shrink the window
        // from left till it is lesser than the minimum
        while (winSum >= minSum) {
            // Window length
            vecSzT winLen = winEndIdx - winStartIdx + 1;
            // Update min window length with specified min sum
            if (0 == minWinLen || winLen < minWinLen) {
                minWinLen = winLen;
                minStartIdx = winStartIdx;
                minEndIdx = winEndIdx;
            }
            // Shrink the window from left by one step
            winSum -= v[winStartIdx];
            ++winStartIdx;
        }
    }

    // Copy the subarray of min length with specified min sum to result
    vector<int> minSumVec;
    if (0 != minWinLen) {
        copy(v.begin() + minStartIdx,
            v.begin() + minEndIdx + 1, back_inserter(minSumVec));
    }

    return minSumVec;
}
