// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

vecSzT
BitonicArray::maximumLocation(const vector<int>& v) {
    // Commence binary search to find the index of maximum
    // element in bitonic array
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    // Do binary search for array maximum and keep adjusting start
    // and end to reduce search range till they end up at same location.
    // That point would be the bitonic array maximum
    while (startIdx < endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] < v[mid + 1]) {
            // Element at midpoint location is not maximum, max element
            // lies at upper part of search range. Update search range.
            startIdx = mid + 1;
        } else { // v[mid] >= v[mid + 1]
            // Element at midpoint location may be maximum or max element
            // lies at lower part of search range. Update search range.
            endIdx = mid;
        }
    }

    return startIdx;
}

long
BitonicArray::orderAgnosticBinSearch(const vector<int>& v, int key,
    vecSzT startIdx, vecSzT endIdx) {

    // No elements in input search range
    if (startIdx > endIdx) {
        return -1;
    }

    // Determine if the given search range elements are in ascending
    // or descending order
    bool ascending = v[startIdx] < v[endIdx];
    // Commence binary search for given key
    while (startIdx <= endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
 
        if (v[mid] == key) {
            return mid; // Key found
        }

        if (ascending) {
            // Search range has elements in ascending order
            if (v[mid] < key) {
                // Upper part of search range should have the key
                startIdx = mid + 1;
            } else { // v[mid] > key
                // Lower part of search range should have the key
                if (0 == endIdx) {
                    break;
                }
                endIdx = (0 == mid) ? 0 : mid - 1;
            }
        } else {
            // Search range has elements in descending order
            if (v[mid] < key) {
                // Lower part of search range should have the key
                if (0 == endIdx) {
                    break;
                }
                endIdx = (0 == mid) ? 0 : mid - 1;
            } else { // v[mid] > key
                // Upper part of search range should have the key
                startIdx = mid + 1;
            }
        }
    }

    // key not found in given search range
    return -1;
}

long
BitonicArray::search(const vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Find index of maximum element in input bitonic array
    vecSzT maxIdx = maximumLocation(v);

    // Input bitonic array can be divided into 2 parts
    // Ascending elements array [0, maxIdx]
    // Descending elements array [maxIdx + 1, v.size() - 1]
    // Do a order agnostic binary search for key in both the above
    // 2 parts of bitonic array separately for given key
    long keyIdx = orderAgnosticBinSearch(v, key, 0, maxIdx);
    if (-1 != keyIdx) {
        // Key found in ascending part of array
        return keyIdx;
    }

    // Key not found in ascending part of array, search in descending part
    return orderAgnosticBinSearch(v, key, maxIdx + 1, v.size() - 1);
}
