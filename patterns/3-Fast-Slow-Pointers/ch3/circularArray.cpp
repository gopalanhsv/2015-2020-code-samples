// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "circularArray.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

bool
CircularArray::hasCycle(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Iterate over each element of the vector sequentially
    for (vecSzT i = 0; i != v.size(); ++i) {

        // Search for cycle in forward direction, if current element
        // is +ve, else in backward direction. All elements should
        // have the same sign in a cycle, else direction will reverse
        // on sign change
        bool forwardDir = (v[i] >= 0);
        // Check for cycle commencing from element at current index
        vecSzT slowIdx = i;
        vecSzT fastIdx = i;
        bool dirChangeOrHalt = false;
        // Have 2 pointers fast and slow. Fast is evaluated twice per
        // iteration which slow is evaluated once. Check to see if the
        // fast catches up with slow (cycle presence) or there is a
        // direction change/halt condition encountered at end of every
        // iteration (cycle absence)
        do {
            // Slow pointer evaluated once per iteration
            slowIdx = findNextHopIdx(v, slowIdx, forwardDir, dirChangeOrHalt);
            if (!dirChangeOrHalt) {
                // Fast pointer evaluated twice per iteration
                fastIdx =
                    findNextHopIdx(v, fastIdx, forwardDir, dirChangeOrHalt);
                if (!dirChangeOrHalt) {
                    fastIdx =
                        findNextHopIdx(v, fastIdx, forwardDir, dirChangeOrHalt);
                }
            }
        } while (!dirChangeOrHalt && slowIdx != fastIdx);

        if (!dirChangeOrHalt && slowIdx == fastIdx) {
            return true;
        }
    }

    return false;
}

int
CircularArray::findNextHopIdx(const vector<int>& v,
    vecSzT currElemIdx, bool forwardDir, bool& dirChangeOrHalt) {
    // Compute index of next hop
    vecSzT nextElemIdx = ((int)currElemIdx + v[currElemIdx]) % v.size();
    // Check for direction change
    if ((forwardDir && v[nextElemIdx] < 0) ||
        (!forwardDir && v[nextElemIdx] > 0)) {
        dirChangeOrHalt = true;
    }

    // Halt condition the next element index as indicated
    // from current element is same as current
    if (nextElemIdx == currElemIdx) {
        dirChangeOrHalt = true;
    }

    return nextElemIdx;
}
