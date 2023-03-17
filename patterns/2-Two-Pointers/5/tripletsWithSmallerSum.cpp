// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "tripletsWithSmallerSum.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;

// Statics, globals, typedefs

vector<vector<int> >
TripletsWithLesserSum::searchTriplets(vector<int> v, int tSum) {
    if (v.size() < 3) {
        throw domain_error("Error! Input vector of invalid size!");
    }

    // Sort vector elements in ascending order
    sort(v.begin(), v.end());
    // Eliminate duplicates
    vecSzT nxtNonDupIdx = 1;
    for (vecSzT i = 1; i != v.size(); ++i) {
        if (v[i] != v[nxtNonDupIdx - 1]) {
            v[nxtNonDupIdx++] = v[i];
        }
    }
    v.erase(v.begin() + nxtNonDupIdx, v.end());

    vector<vector<int> > tripletsV;
    // Iterate over all elements of the vector sequentially
    // from 1st to second last
    for (vecSzT i = 0; i != v.size() - 1; ++i) {
        // Current element at index i is X
        // Need to find all pairs Y, Z in remainder of vector
        // such that triplets X + Y + Z < tSum or
        // Pairs Y & Z in remainder of vector [i + 1, v.size()) range
        // such that Y + Z < tSum - X
        searchPairs(v, tSum - v[i], i, tripletsV);
    }

    return tripletsV;
}

void
TripletsWithLesserSum::searchPairs(const vector<int>& v, int tSum,
    vecSzT firstElemIdx, vector<vector<int> >& tripletsV) {

    int firstElem = v[firstElemIdx];

    vecSzT sIdx = firstElemIdx + 1;
    vecSzT eIdx = v.size() - 1;

    // In vector range [sIdx, eIdx], find all pairs lesser than tSum
    // Start with elements at two pointers sIdx, eIdx and move these two
    // pointers towards each other
    while (sIdx < eIdx) {
        // Compute sum of elements indicated by two ptrs sIdx & eIdx
        int ptrElemsSum = v[sIdx] + v[eIdx];
        if (ptrElemsSum < tSum) {
            // Pairs lesser than target sum found =>
            // Triplets found lesser than target sum
            // Since all elements in range [sIdx + 1, eIdx) are lesser
            // than element at eIdx, all these elements will be part of
            // triples lesser than target sum
            for (vecSzT k = sIdx + 1; k <= eIdx; ++k) {
                vector<int> triplet{firstElem, v[sIdx], v[k]};
                tripletsV.push_back(triplet);
            }
            // Advance left pointer
            ++sIdx;
        } else {
            // Pairs more than target sum found => Triplets more than target sum
            // Need to find pair with lesser sum => move end index to left
            --eIdx;
        }
    }
}
