// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;
using std::vector;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vector<int>::size_type
Array::longestSubarrayWithAll1sPostReplacement(
    const vector<int>& v, unsigned maxAllowedReplacements) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == maxAllowedReplacements) {
        throw domain_error("Error! Invalid allowed replacements!");
    }

    // Tracks number of 1's within sliding window subarray delimited
    // by the range [sWinStartIdx, sWinEndIdx]
    vecSzT sWinOnesCnt = 0;
    vecSzT sWinSizeWithMostOnes = 0;
    vecSzT sWinStartIdx = 0;
    // Extend the sliding window [sWinStartIdx, sWinEndIdx] one element
    // to right at each step by including one more element
    for (vecSzT sWinEndIdx = 0; sWinEndIdx != v.size(); ++sWinEndIdx) {
        // Rightmost element added to sliding window is a 1
        if (v[sWinEndIdx] == 1) {
            ++sWinOnesCnt;
        }

        // Compute window length
        vecSzT sWinLen = sWinEndIdx - sWinStartIdx + 1;
        // Shrink window from left if number of 0's within the subarray
        // which can be completely replaced by 1's exceed permissible value
        if (sWinLen - sWinOnesCnt > maxAllowedReplacements) {
            if (v[sWinStartIdx] == 1) {
                // Leftmost element is 1, adjust the 1's counter
                --sWinOnesCnt;
            }
            // Window shrunk from left
            ++sWinStartIdx;
            --sWinLen;
        }
        // Update potential subarray size of all 1's
        sWinSizeWithMostOnes = max(sWinSizeWithMostOnes, sWinLen);
    }

    return sWinSizeWithMostOnes;
}
