// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "partitionIntegerSet.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::accumulate;

// Statics, globals, typedefs

bool
twoEqualSumSubsetsRecursive(const vector<int>& v, vecSzT nElems, int sum) {
    // Base cases
    // Sum = 0, partition always possible using null sets
    if (0 == sum) {
        return true;
    }
    // Sum != 0 & num elements to consider is 0 => partitioning
    // impossible as 0 elements imply 0 sum
    if (0 != sum && 0 == nElems) {
        return false;
    }

    // Partitioning into 2 equal sum subsets (of value 'sum') is to be attempted
    // for the 1st nElems elements of vector v 
    // Partitioning can be done in two ways -
    // 1. If last element of vector v (i.e 'nElems' element) exceeds sum,
    //    consider partitioning using 1st 'nElems - 1' elements of vector v
    //    excluding the last element
    bool canPartitionExcludingLastElem =
        twoEqualSumSubsetsRecursive(v, nElems - 1, sum);
    if (v[nElems - 1] > sum) {
        return canPartitionExcludingLastElem;
    }

    // 2. If last element of vector v (i.e 'nElems' element) is <= sum,
    //    consider partitioning using 1st 'nElems - 1' elements of vector v 
    //    for remainder sum after including last element; in addition to
    //    partitioning excluding last element
    bool canPartitionIncludingLastElem =
        twoEqualSumSubsetsRecursive(v, nElems - 1, sum - v[nElems - 1]);
    
    return canPartitionIncludingLastElem || canPartitionExcludingLastElem;
}

bool
twoEqualSumSubsetRecursive(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Sum up vector contents
    int sum = accumulate(v.begin(), v.end(), 0);
    // Sum is odd => partitioning into 2 subsets with same set impossible
    if (0 != sum % 2) {
        return false;
    }

    // Figure out whether the given vector can be split into 2 equal
    // sum subsets of given sum recursively
    return twoEqualSumSubsetsRecursive(v, v.size(), sum / 2);
}

bool
twoEqualSumSubsetsUsingDPMemoization(const vector<int>& v,
    vecSzT nElems, int sum, vector<vector<int> >& equalSumSubsetTbl) {
    // Base cases
    // Sum = 0, partition always possible using null sets
    if (0 == sum) {
        return true;
    }
    // Sum != 0 & num elements to consider is 0 => partitioning
    // impossible as 0 elements imply 0 sum
    if (0 != sum && 0 == nElems) {
        return false;
    }

    // Check up the lookup table
    if (-1 != equalSumSubsetTbl[nElems][sum]) {
        return equalSumSubsetTbl[nElems][sum];
    }

    // Partitioning into 2 equal sum subsets (of value 'sum') is to be attempted
    // for the 1st nElems elements of vector v 
    // Partitioning can be done in two ways -
    // 1. If last element of vector v (i.e 'nElems' element) exceeds sum,
    //    consider partitioning using 1st 'nElems - 1' elements of vector v
    //    excluding the last element
    bool canPartitionExcludingLastElem =
        twoEqualSumSubsetsUsingDPMemoization(v, nElems - 1, sum, equalSumSubsetTbl);
    if (v[nElems - 1] > sum) {
        equalSumSubsetTbl[nElems][sum] = canPartitionExcludingLastElem;
        return canPartitionExcludingLastElem;
    }

    // 2. If last element of vector v (i.e 'nElems' element) is <= sum,
    //    consider partitioning using 1st 'nElems - 1' elements of vector v 
    //    for remainder sum after including last element; in addition to
    //    partitioning excluding last element
    bool canPartitionIncludingLastElem =
        twoEqualSumSubsetsUsingDPMemoization(v, nElems - 1,
            sum - v[nElems - 1], equalSumSubsetTbl);

    equalSumSubsetTbl[nElems][sum] =
        canPartitionIncludingLastElem || canPartitionExcludingLastElem;
    return equalSumSubsetTbl[nElems][sum];
}

bool
twoEqualSumSubsetsUsingDPMemoization(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Sum up vector contents
    int sum = accumulate(v.begin(), v.end(), 0);
    // Sum is odd => partitioning into 2 subsets with same set impossible
    if (0 != sum % 2) {
        return false;
    }

    // Lookup table for checking up whether its possible to partition
    // certain elements of vector 'v' into two equal sum subsets for a
    // particular sum (as identified by the column index). The row index
    // identifies the number of elements at the beginning of the
    // vector 'v' to be considered for partitioning.
    vector<vector<int> >
        equalSumSubsetTbl(v.size() + 1, vector<int>(sum + 1, -1));

    // Figure out whether the given vector can be split into 2 equal
    // sum subsets of given sum recursively using DP memoization
    return twoEqualSumSubsetsUsingDPMemoization(v, v.size(),
        sum / 2, equalSumSubsetTbl);
}

bool
twoEqualSumSubsetsUsingDPTabulation(const vector<int>& v, int sum) {
    // Lookup table for checking up whether its possible to partition
    // certain elements of vector 'v' into two equal sum subsets for a
    // particular sum (as identified by the column index). The row index
    // identifies the number of elements at the beginning of the
    // vector 'v' to be considered for partitioning.
    vector<vector<int> >
        equalSumSubsetTbl(v.size() + 1, vector<int>(sum + 1, -1));

    // Initialize the DP lookup table

    // Sum value 0 implies partition always possible using null sets
    // irrespective of the number of set elements
    for (vecVecSzT n = 0; n != v.size() + 1; ++n) {
        equalSumSubsetTbl[n][0] = 1 ;
    }

    // Sum != 0 & num elements to consider being 0 => partitioning
    // impossible as 0 elements imply 0 sum
    for (vecSzT s = 1; s != sum + 1; ++s) {
        equalSumSubsetTbl[0][s] = 0;
    }

    // Populate the lookup table
    for (vecVecSzT n = 1; n != v.size() + 1; ++n) {
        for (vecSzT s = 1; s != sum + 1; ++s) {
            // Partitioning can be done in two ways -
            // 1. If last element of vector v (i.e 'n' element) exceeds sum,
            //    consider partitioning using 1st 'n - 1' elements of vector v
            //    excluding the last element
            // 2. If last element of vector v (i.e 'nElems' element) is <= sum,
            //    consider partitioning using 1st 'nElems - 1' elements of vector v 
            //    for remainder sum after including last element; in addition to
            //    partitioning excluding last element
            if (v[n - 1] <= sum) {
                equalSumSubsetTbl[n][s] = equalSumSubsetTbl[n - 1][s - v[n - 1]];
            }

            equalSumSubsetTbl[n][s] =
                equalSumSubsetTbl[n][s] || equalSumSubsetTbl[n - 1][s];
        }
    }

    return equalSumSubsetTbl[v.size()][sum];
}

bool
twoEqualSumSubsetsUsingDPTabulation(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Sum up vector contents
    int sum = accumulate(v.begin(), v.end(), 0);
    // Sum is odd => partitioning into 2 subsets with same set impossible
    if (0 != sum % 2) {
        return false;
    }

    // Figure out whether the given vector can be split into 2 equal
    // sum subsets using DP Tabulation for given sum
    return twoEqualSumSubsetsUsingDPTabulation(v, sum / 2);
}

