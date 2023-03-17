// System headers
#include <vector>

// Local includes
#include "findInsertLocationInSortedArray.h"

// Using declarations
using std::vector;

// Statics, typedefs, globals

vector<int>::size_type
findInsertPosition(const vector<int>& v, int key) {
    // Empty vector
    if (v.empty()) {
        return 0;
    }

    typedef vector<int>::size_type vecSzT;
    vecSzT lo = 0;
    vecSzT hi = v.size() - 1;
    vecSzT mid, insertPos;

    // Do a modified binary search to search for the
    // insert location
    while (lo <= hi) {

        // Compute midpoint of search range
        mid = lo + (hi - lo) / 2;

        if (v[mid] == key) {
            // Key already present in vector, so just return the
            // key location index
            insertPos = mid;
            break;
        } else if (v[mid] > key) {
            // Key location should be at left of midpoint. So
            // continue search in that range, but potential insert
            // position will be the midpoint index if key is not found
            // and search terminates in next iteration
            hi = mid - 1;
            insertPos = mid;  
        } else {
            // v[mid] < key
            // Key location should be at right of midpoint. So
            // continue search in that range, but potential insert
            // position will be to right of midpoint index if key is
            // not found and search terminates in next iteration
            lo = mid + 1;
            insertPos = mid + 1;  
        }
    }

    return insertPos;
}
