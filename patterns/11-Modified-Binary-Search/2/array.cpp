// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::domain_error;
using std::vector;

// Statics, typedefs, globals

int
Array::ceiling(const vector<int>& v, int k) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Base case : Given key is beyond search range
    if (k > v[v.size() - 1]) { 
        // Key is bigger than all elements in the array
        // No ceiling exists
        return -1;
    }
    if (k < v[0]) {
        // Key is smaller than all elements in the array
        // Ceiling would be first array element
        return v[0];
    }

    // Commence binary search for given key
    typedef vector<int>::size_type vecSzT;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] == k) {
            // Key found. Its ceiling would be the same
            return v[mid];
        }

        if (v[mid] > k) {
            // Search in lower half of current search range
            if (0 == endIdx && 0 == mid) {
                break;
            }
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else {
            // Search in upper half of current search range
            startIdx = mid + 1;
        }
    }

    // Key is not found at end of search. At this point startIdx >= endIdx,
    // startIdx will point to first element greater than key (hence ceiling)
    return v[startIdx];
}

int
Array::floor(const vector<int>& v, int k) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Base case : Given key is beyond search range
    if (k > v[v.size() - 1]) { 
        // Key is bigger than all elements in the array
        // Floor would be last array element
        return v[v.size() - 1];
    }
    if (k < v[0]) {
        // Key is smaller than all elements in the array
        // No floor exists
        return -1;
    }

    // Commence binary search for given key
    typedef vector<int>::size_type vecSzT;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] == k) {
            // Key found. Its floor would be the same
            return v[mid];
        }

        if (v[mid] > k) {
            // Search in lower half of current search range
            if (0 == endIdx && 0 == mid) {
                break;
            }
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else {
            // Search in upper half of current search range
            startIdx = mid + 1;
        }
    }

    // Key is not found at end of search. At this point startIdx >= endIdx,
    // endIdx will point to first element lesser than key (hence floor)
    return v[endIdx];
}
