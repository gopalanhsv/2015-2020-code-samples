// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "peakElement.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, and globals

int
peakElementInVecBruteForce(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;
    vecSzT n = v.size();
    // Trivial case of single element vector
    if (1 == n) {
        return v[n];
    }

    // Trivial case of last/first element being the peak element
    if (v[n - 1] > v[n - 2]) {
        return v[n - 1];
    }
    if (v[1] > v[0]) {
        return v[1];
    }

    // Examine the entire contents of the vector except 1st and last element
    // one by one till an element is found which is greater than its neighbour
    for (vecSzT i = 1; i != n - 1; ++i) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            return v[i];
        }
    }

    // All elements are equal. Return last element
    return v[n - 1];
}

int
peakElementInVecDivAndConquer(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;
    vecSzT n = v.size();
    // Trivial case of single element vector
    if (1 == n) {
        return v[n];
    }

    // Modified binary search to find the peak element
    vecSzT l = 0;
    vecSzT r = n - 1;
    vecSzT mid;
    while (l <= r) {
        // Find the element at the middle of the range
        mid = l + (r - l)/ 2;

        // Search reached end of range, return
        if (mid == 0 || mid == n - 1) {
            return v[mid];
        }

        // Mid Element is greater than its neighbours, so it is
        // peak element
        if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) {
            return v[mid];
        }

        if (v[mid] > v[mid - 1]) {
            // Mid element is greater than element to its left,
            // so peak element would be in right subarray
            l = mid + 1;
        } else {
            // Mid element is lesser than element to its right,
            // so peak element would be in left subarray
            r = mid - 1;
        }
    }

    // All elements are equal. Return mid element
    return v[mid];
}
