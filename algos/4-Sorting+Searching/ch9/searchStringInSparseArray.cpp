// System headers
#include <vector>
#include <string>
#include <iostream>

// Local includes
#include "searchStringInSparseArray.h"

// Using declarations
using std::string;
using std::vector;

// Statics, typedefs, globals

bool
searchStringInSparseArray(const vector<string>& v, const string& key) {
    // Empty input vector
    if (v.empty()) {
        return false;
    }

    typedef vector<string>::size_type vecSzT;
    vecSzT lo = 0;
    vecSzT hi = v.size() - 1;

    // Modified binary search
    while (lo <= hi) {

        // Compute midpoint of search range
        vecSzT mid = lo + (hi - lo) / 2;

        // If null string at midpoint of binary search range, find nearest
        // non-null string and commence search from there
        if (v[mid] == "") {
            vecSzT l, r;
            r = mid + 1;
            l = (mid > lo) ? mid - 1 : lo; // Avoid rollover as l is always +ve
            // Attempt to reset midpoint index to nearest non-null string on
            // either side of calculated midpoint
            while (l >= lo && r <= hi) {
                if (v[l] != "") {
                    mid = l;
                    break;
                }

                if (v[r] != "") {
                    mid = r;
                    break;
                }

                // End of range reached with no non-null element found,
                // implies search failure
                if (l == lo && r == hi) {
                    return false;
                }

                l = (l > lo) ? --l : lo; // Avoid rollover as l is always +ve
                ++r;
            }

        }

        // Now compare value at search midpoint with key
        if (v[mid] == key) {
            // Key found
            std::cout << " Found at " << mid << std::endl;
            return true;
        } else if (v[mid] > key) {
            // Key less than mid, continue search to left of mid
            if (mid == lo) {
                break; // Reached end of range, so exit
            }
            hi = mid - 1;
        } else {
            // Key more than mid, continue search to right of mid
            lo = mid + 1;
        }
    }

    return false;
}
