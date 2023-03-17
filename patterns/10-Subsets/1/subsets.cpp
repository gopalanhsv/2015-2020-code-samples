// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "subsets.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

vector<vector<int> >
Subset::determineSubsets(const vector<int>& nv) {
    if (nv.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Vector of subsets. Initialize with empty subset
    vector<vector<int> > subsetsV;
    subsetsV.push_back({});

    // Iterate over all the numbers of input vector whose subsets
    // are to be determined sequentially one by one
    for (auto n : nv) {
        // Insert the current number being processed in the input
        // vector into copies of all the existing subsets determined
        // as of now to create new subsets. Append the newly created
        // subsets to the vector of subsets from which they were created

        // Iterate over all subsets created uptill the previous iteration
        typedef vector<vector<int> >::size_type vecVecSzT;
        vecVecSzT subsetVecSz = subsetsV.size();
        for (vecVecSzT i = 0; i != subsetVecSz; ++i) {
            // Create a copy of subset being processed now (created in
            // previous iterations)
            vector<int> newSubSet(subsetsV[i]);
            // Append the current element of input vector being processed
            // to the subset created above to form a new subset.
            newSubSet.push_back(n);
            // Append new subset to the vector of subsets
            subsetsV.push_back(newSubSet);
        }
    }

    return subsetsV;
}
