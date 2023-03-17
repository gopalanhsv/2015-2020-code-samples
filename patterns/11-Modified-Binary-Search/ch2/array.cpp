// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::domain_error;
using std::vector;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

long
RotatedArray::search(const std::vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // In a sorted array which is rotated, half the array would
    // be sorted in ascending order after rotation, the other half
    // wont be. So at each step of binary search will narrow down
    // the fact as to whether key lies in the sorted part of rotated
    // array or in the other part
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        // Compute mid point location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] == key) {
            // Key found
            return mid;
        }

        if (v[startIdx] <= v[mid]) {
            // Lower part of the rotated array is in sorted order
            // Check if key lies in sorted range
            if (v[startIdx] <= key && key < v[mid]) {
                // Key lies in lower/sorted range of rotated array
                if (0 == endIdx) {
                    break;
                }
                endIdx = (mid == 0) ? 0 : endIdx - 1;
            } else {
                // Key lies in upper/unsorted range of rotated array
                startIdx = mid + 1;
            }
        } else { // v[startIdx] > v[mid]
            // Upper part of the rotated array is in sorted order
            // Check if key lies in sorted range
            if (v[mid] < key && key <= v[endIdx]) {
                // Key lies in upper/sorted range of rotated array
                startIdx = mid + 1;
            } else {
                // Key lies in lower/unsorted range of rotated array
                if (0 == endIdx) {
                    break;
                }
                endIdx = (0 == mid) ? 0 : endIdx - 1;
            }
        }
    }

    // Key not found
    return -1;
}

long
RotatedArray::searchWithDuplicates(const std::vector<int>& v, int key) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // In a sorted array which is rotated with duplicates, half the array
    // would be sorted in ascending order after rotation, the other half
    // wont be. So at each step of binary search will narrow down the fact
    // as to whether key lies in the sorted part of rotated array or in
    // the other part. Since duplicates are present, it may happen that
    // start, end and midpoint of search range may end up having the same
    // values -- in this particular case search range is narrowed by skipping
    // an element from start and end of range at each iteration, till this
    // case ceases too occur
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        // Compute mid point location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] == key) {
            // Key found
            return mid;
        }

        if ((v[startIdx] == v[mid]) && (v[mid] == v[endIdx])) {
            // Due to duplicates, start, end and mid of search range have
            // identical values. Reduce search range by skipping an
            // element from start and end each
            ++startIdx;
            if (0 == endIdx) {
                break;
            }
            --endIdx;

        } else {

            // start, end, and mid location dont have identical values
            // Narrowing search range done using binary technique

            if (v[startIdx] <= v[mid]) {
                // Lower part of the rotated array is in sorted order
                // Check if key lies in sorted range
                if (v[startIdx] <= key && key < v[mid]) {
                    // Key lies in lower/sorted range of rotated array
                    if (0 == endIdx) {
                        break;
                    }
                    endIdx = (mid == 0) ? 0 : endIdx - 1;
                } else {
                    // Key lies in upper/unsorted range of rotated array
                    startIdx = mid + 1;
                }
            } else { // v[startIdx] > v[mid]
                // Upper part of the rotated array is in sorted order
                // Check if key lies in sorted range
                if (v[mid] < key && key <= v[endIdx]) {
                    // Key lies in upper/sorted range of rotated array
                    startIdx = mid + 1;
                } else {
                    // Key lies in lower/unsorted range of rotated array
                    if (0 == endIdx) {
                        break;
                    }
                    endIdx = (0 == mid) ? 0 : endIdx - 1;
                }
            }

        }
    }

    // Key not found
    return -1;
}
