// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "targetSum.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;

// Typedefs, statics, globals

vector<vector<int> >
QuadrapletsAddingUptoTarget::find(std::vector<int> v, int target) {
    if (v.size() < 4) {
        throw domain_error("Error! Invalid input vector!");
    }

    // Sort the input vector
    sort(v.begin(), v.end());

    vector<vector<int> > quadV;

    // Iterate over all but last three items of vector sequentially
    // Attempt to use current item at index 'i'  as one of the
    // quadraplets and search for other 3 items of quadraplets in 
    // remaining vector range [i + 1, v.size() - 4]
    for (vecSzT i = 0; i < v.size() - 3; ++i) {
        // Skip duplicates
        if (i > 0 && v[i] == v[i - 1]) {
            continue;
        }

        // Iterate over all items commencing from item next to at index 'i'
        // leaving last two items of vector sequentially
        // Attempt to use current items at index 'i' and 'j' as two of the
        // quadraplets and search for other 2 items of quadraplets in 
        // remaining vector range [j + 1, v.size() - 3]
        for (vecSzT j = i + 1; j < v.size() - 2; ++j) {
            // Skip duplicates
            if (j > i + 1 && v[j] == v[j - 1]) {
                continue;
            }

            // Now search for a pair of numbers which can be paired with the
            // numbers at 'i' & 'j' and added up to give the taregt sum
            searchPairs(v, target, i, j, quadV);
        }
    }

    return quadV;
}

void
QuadrapletsAddingUptoTarget::searchPairs(const vector<int>& v, int target,
    vecSzT firstIdx, vecSzT secondIdx, vector<vector<int> >& quadV) {

    // Assuming that the two members of the quadraplet adding upto target are
    // are firstIdx, and secondIdx; use the two pointer method to search for
    // another two numbers in the vector range commencing from 'secondIdx + 1'
    // such that all of them add up to the target

    // Reduce target sum by values of the first 2 selected numbers
    target = target - v[firstIdx] - v[secondIdx];

    // Init 2 pointers to mark extremeties of search range
    vecSzT l = secondIdx + 1;
    vecSzT r = v.size() - 1;
    // Search in the range [l, r] for 2 numbers adding upto the target
    while (l < r) {
        if (v[l] + v[r] == target) {
            // Quadraplet found
            quadV.push_back(vector<int>{v[firstIdx], v[secondIdx], v[l], v[r]});

            // Skip duplicates and continue search for more quadraplets in the
            // reduced range size
            ++l;
            --r;
            while (l < r && v[l] == v[l - 1]) {
                ++l;
            }
            while (l < r && v[r] == v[r + 1]) {
                --r;
            }
        } else if (v[l] + v[r] < target) {
            // Need to search for bigger pair, search in right part of range
            ++l;
        } else {
            // Need to search for smaller pair, search in left part of range
            --r;
        }
    }
}
