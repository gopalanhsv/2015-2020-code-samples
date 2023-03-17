// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "tripletSumToZero.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;

// Statics, globals, typedefs

vector<vector<int> >
TripletsSumToZero::searchTriplets(vector<int>& v) {
    if (v.size() < 3) {
        throw domain_error("Error! Input vector of invalid size!");
    }

    // Sort vector elements in ascending order
    sort(v.begin(), v.end());

    vector<vector<int> > tripletsV;
    // Iterate over all elements of the vector sequentially
    // from 1st to second last
    for (vecSzT i = 0; i != v.size() - 1; ++i) {
        // Skip duplicate elements to avoid duplicate triplets
        if (i > 0 && v[i] == v[i - 1]) {
            continue;
        }
        // Current element at index i is X
        // Need to find all pairs Y, Z in remainder of vector
        // such that triplets X + Y + Z = 0 or
        // Pairs Y & Z in remainder of vector [i + 1, v.size()) range
        // such that Y + Z = -X
        searchPairWithTargetSum(v, -v[i], i + 1, tripletsV);
    }

    return tripletsV;
}

void
TripletsSumToZero::searchPairWithTargetSum(const vector<int>& v, int tSum,
    vecSzT startIdx, vector<vector<int> >& tripletsV) {

    vecSzT endIdx = v.size() - 1;

    // In vector range [startIdx, endIdx], find all pairs adding upto tSum
    // Start with elements at the two pointers startIdx, endIdx and move
    // these two pointers towards each other
    while (startIdx < endIdx) {
        // Compute diff of element at startIdx from target sum
        int diffFromTSum = tSum - v[startIdx];
        if (diffFromTSum == v[endIdx]) {
            // tSum - v[s] = v[e] OR tSum = v[s] + v[e]
            // Pairs with target sum found => Triplets found
            vector<int> triplet{-tSum, v[startIdx], v[endIdx]};
            tripletsV.push_back(triplet);
            // Advance pointers towards each other
            ++startIdx;
            --endIdx;
            // Skip duplicate elements to avoid duplicate triplets
            while (startIdx < endIdx && v[startIdx] == v[startIdx - 1]) {
                ++startIdx;
            }
            while (startIdx < endIdx && v[endIdx] == v[endIdx + 1]) {
                --endIdx;
            }
        } else if (diffFromTSum < v[endIdx]) {
            // tSum - v[s] < v[e] OR tSum < v[s] + v[e]
            // Need to find pair with lesser sum => move end index to left
            --endIdx;
        } else {
            // tSum - v[s] > v[e] OR tSum > v[s] + v[e]
            // Need to find pair with larger sum => move start index to right
            ++startIdx;
        }
    }
}
