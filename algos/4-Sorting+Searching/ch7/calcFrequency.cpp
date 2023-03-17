// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "calcFrequency.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, globals, typedefs

int
calculateFrequency(const vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;

    // Do binary search to determine start index from where key
    // is present in the vector
    vecSzT start = 1, r, l, mid;
    l = 0;
    r = v.size() - 1;
    while (l <= r) {
        // Compute midpoint
        mid = l + (r  - l) / 2;
        // Search Element present at midpoint. Attempt to continue
        // search for duplicates to left of midpoint if not at
        // beginning of vector
        if (v[mid] == key) {
            start = mid;
            if (start > 0) {
                r = mid - 1;
            } else {
                break;
            }
        } else {
            // Search element not found, continue binary search
            if (v[mid] > key) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    // Do binary search to determine end index at which key
    // is present in the vector
    vecSzT end = 0;
    l = 0;
    r = v.size() - 1;
    while (l <= r) {
        // Compute midpoint
        mid = l + (r  - l) / 2;
        // Search Element present at midpoint. Attempt to continue
        // search for duplicates to right of midpoint if not at
        // end of vector
        if (v[mid] == key) {
            end = mid;
            if (end != v.size() - 1) {
                l = mid + 1;
            } else {
                break;
            }
        } else {
            // Search element not found, continue binary search
            if (v[mid] > key) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    // Difference of the end and start indices of search key gives the
    // occurrence count of key (initialized to 0 & 1) respectively
    // so that key count reduces to 0 if key not found
    return end - start + 1;
}
