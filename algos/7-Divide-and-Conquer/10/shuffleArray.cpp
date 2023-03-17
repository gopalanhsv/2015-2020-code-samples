// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "shuffleArray.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vector<int>
shuffleArrayBruteForce(vector<int> v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    if (0 != v.size() % 2) {
        throw domain_error("Error! Input vector has odd number of elems!");
    }

    // Identify the source location and destination location within array
    vecSzT s;
    vecSzT d;
    for (d = 1, s = v.size() / 2; d < v.size(); d += 2, ++s) {
        // Move element from source to destination by rotating to left
        for (vecSzT k = s; k > d; --k) {
            swap(v[k], v[k - 1]);
        }
    }

    return v;
}

void
shuffleArrayDivideAndConquerRec(vector<int>& v, vecSzT l, vecSzT r) {

    // Recursion termination condition of only 2 element in range [l, r)
    if (r - l <= 2) {
        return;
    }

    // Compute midpoint of half open range [l, r)
    vecSzT m = l + (r - l) / 2;

    // Compute midpoint of range [l, m) (i.e. left subarray midpoint)
    vecSzT lm = l + (m - l) / 2;

    // Swap right half of left subarray [l, m) with
    // left half of right subarray[m + 1, r)
    vecSzT i, j;
    for (i = lm, j = m; i < m; ++i, ++j) {
        swap(v[i], v[j]);
    }

    // Recursively shuffle element in left half and right half of subarray
    shuffleArrayDivideAndConquerRec(v, l, m);
    shuffleArrayDivideAndConquerRec(v, m, r);
}

vector<int>
shuffleArrayDivideAndConquer(vector<int> v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    if (0 != v.size() % 2) {
        throw domain_error("Error! Input vector has odd number of elems!");
    }

    shuffleArrayDivideAndConquerRec(v, 0, v.size());

    return v;
}
