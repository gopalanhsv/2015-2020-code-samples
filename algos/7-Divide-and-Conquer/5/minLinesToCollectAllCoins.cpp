// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "minLinesToCollectAllCoins.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;
using std::min;

// Statics, typedefs and globals
typedef vector<int>::size_type vecSzT;

// Recursively computes the minimum number of lines required to collect
// all coins in the vector bounded in column index range [l, r) of which
// rowsCollectedPerCol is the number of coins per column which have
// already been collected
int
minLinesToCollectAllCoinsRec(const vector<int>& v,
    vecSzT l, vecSzT r, int rowsCollectedPerCol) {
    // Recursion termination condition
    if (l >= r) {
        return 0;
    }


    // Horizontal collection of coins followed by split range collection

    // Collect the coins in the vector v[l, r) horizontally row-wise by
    // drawing horizontal lines from row 0 upto the min height which
    // has coins in all columns range [l, r). Essentially find the column
    // with min height/coins in the range [l, r)
    vecSzT m = l;
    for (vecSzT i = l + 1; i != r; ++i) {
        if (v[i] < v[m]) {
            m = i;
        }
    }
    // Once coins upto min height are collected from all columns in [l, r)
    // via horizontal lines, we are left with two split ranges -
    // 1. Left of min height column in [l, r) = range [l, m)
    // 2. Right of min height column in [l, r) = range [m + 1, r)
    // Min lines if coins in range [l, r) are collected by drawing horizontal
    // lines from bottom row upto min column height and then recursively
    // collecting for remainder two split ranges
    int minHeightHorizontal =
        minLinesToCollectAllCoinsRec(v, l, m, v[m]) + // # lines range [l, m)
        minLinesToCollectAllCoinsRec(v, m + 1, r, v[m]) + // # lines range [m + 1, r)
        v[m] - rowsCollectedPerCol; // # horz lines

    // Vertical collection of coins
    // Min lines if all coins in range collected via vertical lines would be
    // number of columns in the range [l, r)
    int minHeightVertical = r - l;

    // Min lines reqd would be min of either vertical or horizontal procedure
    return min(minHeightVertical, minHeightHorizontal);
}

int
minLinesToCollectAllCoins(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    return minLinesToCollectAllCoinsRec(v, 0, v.size(), 0);
}
