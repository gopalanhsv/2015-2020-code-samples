// System headers
#include <vector>

// Local includes
#include "mergeSort.h"

// Using declaration
using std::copy;
using std::vector;
using std::back_inserter;

// Statics, globals, typedefs
typedef vector<int>::size_type vecSzT;


void
merge(vector<int>& v, vecSzT lo, vecSzT mid, vecSzT hi) {
    // Copy the vector halves which are sorted independently to
    // 2 different (lower and upper) vecs to commence merging
    vector<int> lower, upper;
    copy(v.begin() + lo, v.begin() + mid + 1, back_inserter(lower));
    copy(v.begin() + mid + 1, v.begin() + hi + 1, back_inserter(upper));

    vecSzT lowerIdx, upperIdx, mergedIdx;
    lowerIdx = 0;
    upperIdx = 0;
    mergedIdx = lo;

    // Examine each content of lower and upper sorted vecs and merge
    // them till either of the vecs are fully examined
    while (lowerIdx != lower.size() && upperIdx != upper.size()) {
        if (lower[lowerIdx] <= upper[upperIdx]) {
            v[mergedIdx++] = lower[lowerIdx++];
        } else {
            v[mergedIdx++] = upper[upperIdx++];
        }
    }

    // Copy the remaining elements from lower vec to destination
    while (lowerIdx != lower.size()) {
        v[mergedIdx++] = lower[lowerIdx++];
    }

    // Copy the remaining elements from upper vec to destination
    while (upperIdx != upper.size()) {
        v[mergedIdx++] = upper[upperIdx++];
    }
}

void
mergeSort(vector<int>& v, vecSzT lo, vecSzT hi) {
    // Base case of single element vector
    if (lo >= hi) {
        return;
    }

    // Calc vector midpoint
    vecSzT mid = lo + (hi - lo) / 2;

    // Sort the lower half
    mergeSort(v, lo, mid);

    // Sort the upper half
    mergeSort(v, mid + 1, hi);

    // Merge the sorted vector halves
    merge(v, lo, mid, hi);
}

void
mergeSort(vector<int>& v) {
    if (v.empty()) {
        return;
    }
    mergeSort(v, 0, v.size() - 1);
}
