// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Local includes
#include "quickSort.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;
using std::min;
using std::swap;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vecSzT
selectPivot(vecSzT lo, vecSzT hi) {
    // Select 3 random indices in range [lo, hi]
    vecSzT aIdx = lo + (rand() % (hi - lo + 1));
    vecSzT bIdx = lo + (rand() % (hi - lo + 1));
    vecSzT cIdx = lo + (rand() % (hi - lo + 1));

    // Compute their median and select it as pivot idx
    return min(max(aIdx, bIdx), max(bIdx, cIdx));
    //return max(min(aIdx, bIdx), min(max(aIdx, bIdx), cIdx));
}

vecSzT
partition(vector<int>& v, vecSzT lo, vecSzT hi) {
    // Choose & get the index of pivot element
    vecSzT pi = selectPivot(lo, hi);
    // Move the pivot element to end of partitioning range
    swap(v[pi], v[hi]);
    // Move all elements lesser than pivot in the
    // range [lo, hi] to the lower half of range
    vecSzT idx = lo;
    for (vecSzT i = lo; i != hi; ++i) {
        if (v[i] <= v[hi]) {
            swap(v[i], v[idx]);
            ++idx;
        }
    }
    // Move pivot element to its proper location (index idx) so that
    // input vector range gets properly partitioned around pivot
    swap(v[hi], v[idx]);

    return idx;
}

void
quickSort(vector<int>& v, vecSzT lo, vecSzT hi) {
    if (lo < hi) {
        // Partition the input vector into 2 halves around the pivot element.
        // Pivot element comes to its proper sorted location after partitioning
        vecSzT pivotIdx = partition(v, lo, hi);
        // Sort the lower half of the vector
        if (pivotIdx > 0) { // To avoid overflow
            quickSort(v, lo, pivotIdx - 1);
        }
        // Sort the upper half of the vector
        quickSort(v, pivotIdx + 1, hi);
    }
}

void
quickSort(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    srand(time(NULL));
    quickSort(v, 0, v.size() - 1);
}
