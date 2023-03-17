// System headers
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>

// Local includes
#include "fruits2Baskets.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::domain_error;
using std::max;

// Statics, typedefs, globals
typedef vector<char>::size_type vecSzT;

unsigned
FruitsToBaskets::maxContiguousFruitsToBaskets(
    const vector<char>& fruitV, unsigned nBaskets) {
    if (fruitV.empty()) {
        throw domain_error("Error! Empty fruits list!");
    }
    if (0 == nBaskets) {
        throw domain_error("Error! Invalid number of baskets!");
    }

    // Hash table which tracks number of fruits per basket type
    // within the slding window/contiguous subarray
    unordered_map<char, unsigned> fruitFreqCntTbl;
    vecSzT winStartIdx = 0;
    vecSzT maxWinLen = 0;
    // Keep expanding the contiguous subarray of fruits delimited by
    // the sliding window [winStartIdx, winEndIdx], one fruit at a
    // time to the right. Adjust the sliding window such that it never
    // contains more fruit types than the number of baskets
    for (vecSzT winEndIdx = 0; winEndIdx != fruitV.size(); ++winEndIdx) {
        // Add new fruit to right of sliding window and expand it. Update
        // the frequency count of fruits
        char rightMostFruit = fruitV[winEndIdx];
        fruitFreqCntTbl[rightMostFruit]++;

        // Shrink the window from the left to ensure that the number of
        // fruit types/baskets required to hold all the fruits within
        // sliding window subarray dont exceed the specified value
        while (fruitFreqCntTbl.size() > nBaskets) {
            // Shrinking sliding window from left
            char leftMostFruit = fruitV[winStartIdx++];
            // Update frequency count of sliding window fruits 
            fruitFreqCntTbl[leftMostFruit]--;
            if (fruitFreqCntTbl[leftMostFruit] == 0) {
                fruitFreqCntTbl.erase(leftMostFruit);
            }
        }

        // Track the maximum num of fruits within the sliding window
        if (fruitFreqCntTbl.size() == nBaskets) {
            maxWinLen = max(maxWinLen, winEndIdx - winStartIdx + 1);
        }
    }

    return maxWinLen;
}
