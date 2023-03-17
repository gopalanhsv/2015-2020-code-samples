// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "subsets.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;

// Statics, typedefs, globals

vector<vector<int> >
Subset::determineSubsetsWithInputDuplicates(vector<int> nv) {
    if (nv.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Sort input vector such the duplicate elements are adjacent
    sort(nv.begin(), nv.end());

    // Vector of subsets. Initialize with empty subset
    vector<vector<int> > subsetsV;
    subsetsV.push_back({});

    typedef vector<vector<int> >::size_type vecVecSzT;
    vecVecSzT startSubSetVecIdx = 0, endSubSetVecIdx;

    // Iterate over all the numbers of sorted input vector whose subsets
    // are to be determined sequentially one by one
    for (vector<int>::size_type i = 0; i != nv.size(); ++i) {

        // For the current number being processed from input vector -
        // 1. If the number is a duplicate of one processed from input
        //    vector in previous iteration, insert the number only into
        //    copies of subsets created during the previous iteration
        //    using the same input number to form new subsets
        // 2. If the number is not a duplicate of one processed from input
        //    vector in previous iteration, insert new number into
        //    copies of all existing subsets determined uptill now to form
        //    new subsets
        // Append the newly created subsets to the vector
        // of subsets from which they were created

        if (i > 0 && nv[i] == nv[i - 1]) {
            // Processed number is duplicate of one previously processed,
            // form new subsets using only the subsets created in previous
            // iteration using the same number
            startSubSetVecIdx = endSubSetVecIdx;
        } else {
            // Processed number is non duplicate, from new subsets using all
            // the subsets created uptill now
            startSubSetVecIdx = 0;
        }
        endSubSetVecIdx = subsetsV.size();

        // Iterate over subset range as per above
        for (vecVecSzT p = startSubSetVecIdx; p != endSubSetVecIdx; ++p) {
            // Create a copy of subset being processed now (created in
            // previous iterations)
            vector<int> newSubSet(subsetsV[p]);
            // Append the current element of input vector being processed
            // to the subset created above to form a new subset.
            newSubSet.push_back(nv[i]);
            // Append new subset to the vector of subsets
            subsetsV.push_back(newSubSet);
        }
    }

    return subsetsV;
}
