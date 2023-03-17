// System headers
#include <vector>
#include <stdexcept>
#include <utility>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::pair;
using std::make_pair;

// Statics, typedefs, globals

pair<long, long>
Array::keyRange(const std::vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Key lies beyond elements at array bounds. Implies
    // key not in range
    if (key < v[0] || key > v[v.size() - 1]) {
        return make_pair<long, long>(-1, -1);
    }

    // Commence binary search for the key lower range
    typedef vector<char>::size_type vecSzT;
    bool keyFound = false;
    vecSzT lo = 0;
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    
    while (startIdx < endIdx) {
        // Compute midpoint location of current search range
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;

        if (v[mid] == key) {
            // Key found
            keyFound = true;
            lo = mid;
            // Continue search in lower part below mid
            // to find lowest position of key location
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else if (v[mid] > key) {
            // Continue search in lower part of range
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else { // v[mid] >= key
            // Continue search in upper part of range
            startIdx = mid + 1;
        }
    }

    if (!keyFound) {
        return make_pair<long, long>(-1, -1);
    }

    // Commence binary search for the key upper range
    vecSzT hi;
    startIdx = 0;
    endIdx = v.size() - 1;
    
    while (startIdx < endIdx) {
        // Compute midpoint location of current search range
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;

        if (v[mid] == key) {
            // Key found
            hi = mid;
            // Continue search in upper part beyond mid
            // to find uppermost position of key location
            startIdx = mid + 1;
        } else if (v[mid] > key) {
            // Continue search in lower part of range
            endIdx = (0 == mid) ? 0 : mid - 1;
        } else { // v[mid] >= key
            // Continue search in upper part of range
            startIdx = mid + 1;
        }
    }

    return make_pair<long, long>(lo, hi);

}
