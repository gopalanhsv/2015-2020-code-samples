// System headers
#include <vector>
#include <stdexcept>
#include <cmath>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

int
Array::minimumDiffFromKey(const std::vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Key lies beyond elements at array bounds. Implies minimium
    // difference element from key would be those at array bounds
    // key not in range
    if (key <= v[0]) {
        return v[0];
    }
    if (key >= v[v.size() - 1]) {
        return v[v.size() - 1];
    }

    // Commence binary search for the key
    typedef vector<char>::size_type vecSzT;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    
    while (startIdx <= endIdx) {
        // Compute midpoint location of current search range
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;

        if (v[mid] == key) {
            // Key found
            return v[mid];
        } else if (v[mid] > key) {
            if (0 == endIdx) {
                break;
            }
            // Continue search in lower part of range
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else { // v[mid] > key
            // Continue search in upper part of range
            startIdx = mid + 1;
        }
    }

    // Key is not found. Search would have ended at startIdx > endIdx.
    // Key would be in range [endIdx, startIdx]
    // Select element from these two indices at minimum difference from key
    if (abs(v[startIdx] - key) < abs(key - v[endIdx])) {
        return v[startIdx];
    } else {
        return v[endIdx];
    }
}
