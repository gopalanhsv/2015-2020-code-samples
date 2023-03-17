// System headers
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

// Local includes
#include "maxSubarraySum.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;

// Statics, typedefs, globals

int
maxSumOfSubArraysBruteForce(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    int maxSum = std::numeric_limits<int>::min();
    typedef vector<int>::size_type vecSzT;
    // Iterate over each element of the vector
    for (vecSzT startIdx = 0; startIdx != v.size(); ++startIdx) {
        // Find the sum of various subarrays starting from the current index
        // moving toward the end of the vector element by element. And select
        // the max sum calculated as such
        int currSubArraySum = 0;
        for (vecSzT endIdx = startIdx; endIdx < v.size(); ++endIdx) {
            currSubArraySum += v[endIdx];
            maxSum = max(maxSum, currSubArraySum);
        }
    }

    return maxSum;
}

inline int
max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int
maxCrossingSum(const vector<int>& v, vecSzT l, vecSzT mid, vecSzT r) {
    // Compute max sum for left part of the subarray
    int maxLeftSum = std::numeric_limits<int>::min();
    int sum = 0;
    for (vecSzT i = mid; i >= l; --i) {
        sum += v[i];
        maxLeftSum = max(sum, maxLeftSum);
        if (0 == i) {
            break; // since i is unsigned  will cause overflow on --i
        } 
    }

    // Compute max sum for right part of the subarray
    int maxRightSum = std::numeric_limits<int>::min();
    sum = 0;
    for (vecSzT i = mid + 1; i <= r; ++i) {
        sum += v[i];
        maxRightSum = max(sum, maxRightSum);
    }

    return maxRightSum + maxLeftSum;
}

// Compute the max subarray sum for the vector subarray
// v demaracated by indices [l, r]
int
maxSumOfSubArraysDivAndConquerRec(const vector<int>& v, vecSzT l, vecSzT r) {
    // Termination case, Left and right indices
    // same => single element subarray
    if (l == r) {
        return v[l];
    }

    // Compute midpoint
    vecSzT mid = l + (r - l) / 2;

    // Divide the subarray into two halves
    // Max subarray sum would the max of the max left subarray sum,
    // max right subarray sum or max sum spanning both the left and right
    // halves with mid element
    return max3(
        maxSumOfSubArraysDivAndConquerRec(v, l, mid), // L subarray
        maxSumOfSubArraysDivAndConquerRec(v, mid + 1, r), // R subarray
        maxCrossingSum(v, l, mid, r)); // spanning L and R with midpoint
}

int
maxSumOfSubArraysDivAndConquer(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    return maxSumOfSubArraysDivAndConquerRec(v, 0, v.size() - 1);
}

// Kadane's algorithm using dynamic programming
int
maxSumOfSubArraysDP(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Keep track of contiguous elements with maximum sum, 
    // updating the global max subarray sum at each step

    // Init max sum to first vector element
    int globalMaxSum = v[0];
    int currMaxSum = v[0];
    // Examine all vector elements in sequence
    for (vecSzT i = 1; i != v.size(); ++i) {
#if 0
        // Keep track of the max sum of contiguous elements each time a new
        // vector element is seen. If new vector element added to contiguous
        // sum results in a higher sum value, update it, otherwise reset the
        // max sum of contiguous elements to start from current element
        if (currMaxSum + v[i] > v[i]) {
            currMaxSum += v[i];
        } else {
            currMaxSum = v[i];
        }
#endif
        currMaxSum = max(v[i], currMaxSum + v[i]);
        // Update the global maximum
        globalMaxSum = max(globalMaxSum, currMaxSum);
    }

    return globalMaxSum;
}
