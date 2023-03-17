// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals
typedef std::vector<int>::size_type vecSzT;

vecSzT
RotatedArray::numRotations(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input array!");
    }

    // 1. Number of times a sorted array is rotated can be determined from
    // the location of pre-rotation start element/minimum array element
    // in the rotated array.
    // 2. Minimum element in rotated array is the only one whose predecessor
    // is greater; all other elements are ordered in ascending order with
    // each being higher than their predecessors
    // 3. A sorted array after rotation would have the property that one half
    // of it will be in sorted order, and the other half would be unsorted.
    // The minimum element would lie in unsorted region (if middle element is
    // not minimum) -- unless the rotation is nil 

    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    // Commence binary search for location of minimum element
    while (startIdx < endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;

        if (mid > startIdx && v[mid - 1] > v[mid]) {
            // Element at mid is one whose preceeding element is greater
            // Would be the minimum element
            return mid;
        }
        if (mid < endIdx && v[mid] > v[mid + 1]) {
            // Element at mid + 1 is one whose preceeding element is greater
            // Would be the minimum element
            return mid + 1;
        }

        // Narrow down search range for locating minimum element/num rotations
        // by leaving out the half of array which is sorted for next iteration
        if (v[startIdx] <= v[mid]) {
            // Lower part of search range is sorted
            // Look for minimum in unsorted upper part
            startIdx = mid + 1;
        } else { // Implies v[mid] < v[endIdx]
            // Lower part of search range is unsorted => upper part sorted
            // Look for minimum in lower part
            if (0 == endIdx) {
                break;
            }
            endIdx = (0 == mid) ? 0 : mid - 1;
        }
    }

    // Array has not been rotated
    return 0;
}

vecSzT
RotatedArray::numRotationsWithArrDuplicates(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input array!");
    }

    // 1. Number of times a sorted array is rotated can be determined from
    // the location of pre-rotation start element/minimum array element
    // in the rotated array.
    // 2. Minimum element in rotated array is the only one whose predecessor
    // is greater; all other elements are ordered in ascending order with
    // each being higher than their predecessors
    // 3. A sorted array after rotation would have the property that one half
    // of it will be in sorted order, and the other half would be unsorted.
    // The minimum element would lie in unsorted region (if middle element is
    // not minimum) -- unless the rotation is nil 

    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    // Commence binary search for location of minimum element
    while (startIdx < endIdx) {
        // Compute midpoint location
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;

        if (mid > startIdx && v[mid - 1] > v[mid]) {
            // Element at mid is one whose preceeding element is greater
            // Would be the minimum element
            return mid;
        }
        if (mid < endIdx && v[mid] > v[mid + 1]) {
            // Element at mid + 1 is one whose preceeding element is greater
            // Would be the minimum element
            return mid + 1;
        }

        // Narrow down search range for locating minimum element/num rotations
        // by leaving out the half of array which is sorted for next iteration
        if (v[startIdx] == v[mid] && v[mid] == v[endIdx]) {
            // Due to duplicates, elements at start, mid and end are same.
            // Narrow the search range by skipping an element from end of
            // search range. Prior to range reduction check for minimum there
            if (v[startIdx] > v[startIdx + 1]) {
                // Element at startIdx + 1 is one whose preceeding element
                // is greater. Would be the minimum element
                return startIdx + 1;
            };
            ++startIdx;
            if (0 == endIdx) {
                break;
            }
            if (v[endIdx - 1] > v[endIdx]) {
                // Element at endIdx is one whose preceeding element
                // is greater. Would be the minimum element
                return endIdx;
            }
            --endIdx;

        } else if (v[startIdx] <= v[mid] || v[mid] > v[endIdx]) {
            // Lower part of search range is sorted
            // Look for minimum in unsorted upper part
            startIdx = mid + 1;
        } else { // Implies v[startIdx] > v[mid] || v[mid] <= v[endIdx]
            // Lower part of search range is unsorted => upper part sorted
            // Look for minimum in lower part
            if (0 == endIdx) {
                break;
            }
            endIdx = (0 == mid) ? 0 : mid - 1;
        }
    }

    // Array has not been rotated
    return 0;
}
