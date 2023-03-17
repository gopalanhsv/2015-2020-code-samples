// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

char
Array::nextLetter(const std::vector<char>& v, char key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Key lies beyond elements at array bounds(or is last element), implies
    // that first element would be next to key, since array is circular
    if (key < v[0] || key >= v[v.size() - 1]) {
        return v[0];
    }

    // Commence binary search for the key
    typedef vector<char>::size_type vecSzT;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        // Compute midpoint location of current search range
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] > key) {
            // Continue search in lower part of range
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else { // v[mid] >= key
            // Continue search in upper part of range
            startIdx = mid + 1;
        }
    }

    // At this point search has ended with key either found/not found
    // and startIdx > endIdx. Since the key is supposed to be in closed
    // range [startIdx, endIdx], the next letter to key would be at
    // startIdx (modulo array size as array is assumed to be circular)
    return v[startIdx % v.size()];
}
