// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <cctype>

// Local includes
#include "tripletSumCloseToTarget.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;

// Statics, globals, typedefs

vector<int>
TripletSumCloseToTarget::searchTriplet(vector<int>& v, int t) {
    if (v.size() < 3) {
        throw domain_error("Error! Input vector of invalid size!");
    }

    // Sort vector elements in ascending order
    sort(v.begin(), v.end());

    vector<int> triplet(3);
    int minDiff = std::numeric_limits<int>::max();
    // Iterate over all elements of the vector sequentially
    // from 1st to second last
    for (vecSzT i = 0; i != v.size() - 1; ++i) {
        // Current element at index i is X

        // Need to find pair Y, Z in range [i + 1, v.size())
        // such that difference of (X + Y + Z) and t is least

        // Have two pointers initially positioned at the endpoints of the
        // range [i + 1, v.size() - 1]. The two pointers indicate position
        // of pairs Y and Z for current X (i.e. v[i]). Move pointers towards
        // each other till we get values of Y & Z such that difference
        // between X + Y + Z and t is the minimum seen so far
        vecSzT sIdx = i + 1;
        vecSzT eIdx = v.size() - 1;
        while (sIdx < eIdx) {
            int currDiff = t - v[i] - v[sIdx] - v[eIdx];
            if (currDiff == 0) {
                // Triplets found with min difference, i.e triplet sum up to
                // given target
                triplet[0] = v[i];
                triplet[1] = v[sIdx];
                triplet[2] = v[eIdx];
                break;
            }

            if (abs(currDiff) < abs(minDiff)) {
                // Triplets found with lesser than min difference (closer to
                // target), so store them
                minDiff = currDiff;
                triplet[0] = v[i];
                triplet[1] = v[sIdx];
                triplet[2] = v[eIdx];
            }

            if (currDiff > 0) {
                // X + Y + Z have smaller sum
                // Need to check for bigger sum pairs Y and Z to increase diff
                // Advance start index
                ++sIdx;
            } else {
                // X + Y + Z have bigger sum
                // Need to check for smaller sum pairs Y and Z to reduce diff
                // Reduce end index
                --eIdx;
            }
        }
    }

    return triplet;
}
