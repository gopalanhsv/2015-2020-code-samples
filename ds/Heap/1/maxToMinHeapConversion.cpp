// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "maxToMinHeapConversion.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, globals, typedefs

vector<int>
convertMaxHeapVecToMinHeap(const vector<int>& maxHeap) {
    if (maxHeap.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Copy max heap vals to tmp heap
    vector<int> v(maxHeap.begin(), maxHeap.end());

    // Max heap vec has values in max heap organization, wherein each
    // parent key is more than or equal to its two children

    // To convert to min heap form, we need to examine all parent node
    // locations and exchange values of parent with the lesser of its
    // two children. Also it is advisable to start from last parent
    // and work towards root; as this will ensure percolation down
    // automatically
    typedef vector<int>::size_type vecSzT;
    // 1 added to avoid infinite loop
    vecSzT parentIdx = (v.size() - 1) / 2 + 1;
    do {
        // Decrementing pIdx here to ensure that last iteration is
        // with pIdx value of 0. Else infinite loop will crop up
        // with pIdx being unsigned type
        --parentIdx;

        // Start min-heapifying from current parent index down to leaf
        vecSzT pIdx = parentIdx;

        while (pIdx < v.size()) {
            // Indices of L & R children
            vecSzT lcIdx = 2 * pIdx + 1;
            vecSzT rcIdx = 2 * pIdx + 2;
            vecSzT minIdx = pIdx;
            // Find the index of child with min value
            if (rcIdx < v.size() && v[minIdx] > v[rcIdx]) {
                minIdx = rcIdx;
            }
            if (lcIdx < v.size() && v[minIdx] > v[lcIdx]) {
                minIdx = lcIdx;
            }
            // Exhange parent with child if child is lesser value
            if (minIdx != pIdx) {
                swap(v[minIdx], v[pIdx]);
                pIdx = minIdx;
            } else {
                // Min heapify done for this parent to child leg
                break;
            }
        }

    } while (parentIdx != 0);

    return v;
}


