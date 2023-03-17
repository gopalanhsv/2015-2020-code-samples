// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

// Local includes

// Using declarations
using std::vector;
using std::sort;
using std::domain_error;
using std::copy;
using std::back_inserter;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;
typedef vector<vector<int> >::size_type vecVecSzT;

void
inputErrorChecks(const vector<vector<int> >& sortedArrays) {
    if (sortedArrays.empty()) {
        throw domain_error("Error! Empty array of sorted arrays!");
    }

    vecSzT n = sortedArrays[0].size();
    for (vecVecSzT i = 1; i != sortedArrays.size(); ++i) {
        if (sortedArrays[i].size() != n) {
            throw domain_error("Error! Mismatch in size of sorted arrays!");
        }
    }

    if (!n) {
        throw domain_error("Error! Sorted arrays are empty!");
    }
}

vector<int>
mergeSortedArraysBruteForce(const vector<vector<int> >& sortedArrays) {
    // Input error checks
    try {
        inputErrorChecks(sortedArrays);
    } catch (domain_error& e) {
        throw e;
    }

    // Iterate over each of individual sorted arrays and append their
    // contents to single vector
    vector<int> mergedVec;
    for (vecVecSzT i = 0; i != sortedArrays.size(); ++i) {
        const vector<int>& v = sortedArrays[i];
        copy(v.begin(), v.end(), back_inserter(mergedVec));
    }

    // Sort the contents of the single vector to which all data of
    // individual sorted arrays is appended
    sort(mergedVec.begin(), mergedVec.end());

    return mergedVec;
}

// Merge the 2 individually sorted ranges [range1Lo, range1Hi]
// and [range2Lo, range2Hi] to a single range[range1Lo, range2Hi]
void
mergeSortedVecs(vecSzT range1Lo, vecSzT range1Hi,
    vecSzT range2Lo, vecSzT range2Hi, vector<int>& v) {

    // Compute the number of elemnts in the 2 sorted ranges
    vecSzT range1Size = range1Hi - range1Lo + 1;
    vecSzT range2Size = range2Hi - range2Lo + 1;

    // Store the elements from the two sorted ranges into 
    // 2 different vectors prior to commencing merge sort
    vector<int> range1Elems;
    for (vecSzT i = 0; i != range1Size; ++i) {
        range1Elems.push_back(v[range1Lo + i]);
    }
    vector<int> range2Elems;
    for (vecSzT i = 0; i != range2Size; ++i) {
        range2Elems.push_back(v[range2Lo + i]);
    }

    // Keep copying the smaller of elements from the two individual
    // sorted vectors to the merged vector till all elements of at least
    // one vector are completely processed
    vecSzT r1Idx = 0;
    vecSzT r2Idx = 0;
    vecSzT mergedIdx = range1Lo;
    while (r1Idx != range1Size && r2Idx != range2Size) {
        if (range1Elems[r1Idx] < range2Elems[r2Idx]) {
            v[mergedIdx++] = range1Elems[r1Idx++];
        } else {
            v[mergedIdx++] = range2Elems[r2Idx++];
        }
    }
    // Copy the unprocessed elements
    while (r1Idx != range1Size) {
        v[mergedIdx++] = range1Elems[r1Idx++];
    }
    while (r2Idx != range2Size) {
        v[mergedIdx++] = range2Elems[r2Idx++];
    }
}

// Sorts and Merges the elements of all sorted vectors in range
// [loVec, hiVec] to the merged vector
void
mergeSortedArraysDivAndConqRec(const vector<vector<int> >& sortedArrays,
    vecVecSzT loVec, vecVecSzT hiVec, vector<int>& mergedVec) {

    vecSzT nVecElems = sortedArrays[0].size();
    // Termination condition, If sorted vector range is a single vector
    // just copy elements of sorted vector to appropriate location in
    // the merged vector
    if (loVec == hiVec) {
        for (vecSzT i = 0; i != nVecElems; ++i) {
            mergedVec[loVec * nVecElems + i] = sortedArrays[loVec][i];
        }
        return;
    }

    // Split the complete range of sorted vectors to be sorted + merged
    // into two halves. 
    vecVecSzT midVec = loVec + (hiVec - loVec) / 2;

    // The two halves are [loVec, midVec] & [midVec + 1, hiVec]
    // Sort and merge the elements individually in the split halves
    // to the mergedVec
    mergeSortedArraysDivAndConqRec(
        sortedArrays, loVec, midVec, mergedVec);
    mergeSortedArraysDivAndConqRec(
        sortedArrays, midVec + 1, hiVec, mergedVec);

    // Merge the above obtained 2 sorted + merged halves
    mergeSortedVecs(loVec * nVecElems, (midVec + 1) * nVecElems - 1,
        (midVec + 1) * nVecElems, (hiVec + 1) * nVecElems - 1, mergedVec);
}

vector<int>
mergeSortedArraysDivAndConq(const vector<vector<int> >& sortedArrays) {
    // Input error checks
    try {
        inputErrorChecks(sortedArrays);
    } catch (domain_error& e) {
        throw e;
    }

    vecVecSzT nArrays = sortedArrays.size();
    vecSzT elemsPerArray = sortedArrays[0].size();
    // vector to hold sorted + merged contents of individual sorted arrays
    vector<int> mergedVec(nArrays * elemsPerArray, 0);

    mergeSortedArraysDivAndConqRec(sortedArrays, 0, nArrays - 1, mergedVec);

    return mergedVec;
}
