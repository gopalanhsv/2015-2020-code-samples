// System headers
#include <vector>
#include <limits>
#include <cstdlib>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

long
InfiniteArray::search(BigArrayReader *arrRdr, int key) {
    if (nullptr == arrRdr) {
        throw domain_error("Error! null array reader!");
    }

    // Determine the range of the big array in which to search
    // for the key using exponential binary search
    size_t startIdx = 0;
    size_t endIdx = 1;
    while (key > arrRdr->get(endIdx)) {
        // key is beyond search range [startIdx, endIdx], Move the start of
        // range to beyoung endIdx and double the search range size
        size_t newStartIdx = endIdx + 1;
        endIdx = endIdx + (endIdx - startIdx + 1) * 2;
        startIdx = newStartIdx;
    }

    // Commence binary search for given key in the search range
    // obtained above, by halving the search range at each step
    while (startIdx <= endIdx) {
        // Compute midpoint location for search range
        size_t mid = startIdx + (endIdx - startIdx) / 2;
        if (key == arrRdr->get(mid)) {
            // Key found
            return mid;
        }

        if (arrRdr->get(mid) < key) {
            // Key lies in upper half of search range above mid
            startIdx = mid + 1;
        } else {
            // Key lies in lower half of search range below mid
            if (0 == endIdx) {
                break;
            }
            endIdx = (0 == mid) ? 0 : mid - 1;
        }
    }

    // Key not found
    return -1;
}
