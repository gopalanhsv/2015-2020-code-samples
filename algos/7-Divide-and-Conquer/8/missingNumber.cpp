// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "missingNumber.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

int
missingNumberBruteForce(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Each element in the sorted contiguous vector [1, 2, .. v.size()]
    // will have its value such that v[i] = i + 1
    // Iterate over the vector elements sequentially
    for (vecSzT i = 0; i != v.size(); ++i) {
        // The first number in sorted vector [1, ..., n] which
        // is ne i + 1 is the missing number
        if (v[i] != i + 1) {
            return i + 1;
        }
    }

    // No missing number
    return -1;
}

int
missingNumberDivideAndConquer(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Binary search to find the missing number
    vecSzT l = 0;
    vecSzT r = v.size() - 1;
    while (l <= r) {
        // Compute midpoint index
        vecSzT m = l + (r - l) / 2;

        // Check if element at midpoint is not equal to expected value
        if (v[m] != m + 1) {
            // Element at midpoint not the expected value => missing
            // element is either at midpoint or preceeding midpoint
            if (0 == m || v[m - 1] == m) {
                // Element at midpoint is the first element out of
                // place and hence the missing element
                return m + 1;
            } else {
                // Element at midpoint is the not missing element
                // Continue search in left subarray to midpoint
                r = m - 1;
            }
        } else {
            // Element at midpoint is equals to expected value
            // So missing element may occur in right subarray to midpoint
            l = m + 1;
        }
    }

    // No missing element
    return -1;
}
