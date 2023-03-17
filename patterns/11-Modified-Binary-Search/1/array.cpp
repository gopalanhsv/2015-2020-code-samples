// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::domain_error;
using std::vector;

// Statics, typedefs, globals

long long
OrderedArray::orderAgnosticBinarySearch(const vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Determine if vector is ascending or descending to tune search technique
    bool ascending = v[0] < v[v.size() - 1];

    // Commence binary search for given key
    typedef vector<int>::size_type vecSzT;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] == key) {
            // Key found
            return mid;
        }

        if (ascending) {
            // Array in ascending order
            if (v[mid] > key) {
                // Search in lower half of range
                if (0 == mid && 0 == endIdx) {
                    break;
                }
                endIdx = (0 == mid) ? 0 : mid - 1;
            } else { // v[mid] < key
                // Search in upper half of range
                startIdx = mid + 1;
            }
        } else {
            // Array in descending order
            if (v[mid] > key) {
                // Search in upper half of range
                startIdx = mid + 1;
            } else { // v[mid] < key
                // Search in lower half of range
                if (0 == mid && 0 == endIdx) {
                    break;
                }
                endIdx = (0 == mid) ? 0 : mid - 1;
            }
        }
    }

    return -1;
}
