// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vector<double>
Array::avgOfContiguousSubArraysBruteForce(
    const vector<int>& v, vecSzT subArrSz) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == subArrSz) {
        throw domain_error("Error! Invalid subarray size!");
    }

    vector<double> avgV;
    // Iterate over contiguous subarray blocks
    for (vecSzT subArrStartIdx = 0;
        subArrStartIdx < (v.size() - subArrSz + 1); ++subArrStartIdx) {
        // Sum up all elements of subarray and find the average
        vecSzT subArrEndIdx = subArrStartIdx + subArrSz - 1;
        double subArrSum = 0.0;
        for (vecSzT i = subArrStartIdx; i <= subArrEndIdx; ++i) {
            subArrSum += v[i];
        }
        // Append the average of subarray sum to result vector
        avgV.push_back(subArrSum / subArrSz);
    }

    return avgV;
}

vector<double>
Array::avgOfContiguousSubArraysSlidingWindow(
    const vector<int>& v, vecSzT subArrSz) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == subArrSz) {
        throw domain_error("Error! Invalid subarray size!");
    }

    // Vector for holding contiguous sub array averages
    vector<double> avgV(v.size() - subArrSz + 1, 0.0);
    double winSum = 0.0; 
    vecSzT winStart = 0;
    // Iterate over all elements of input array
    for (vecSzT winEnd = 0; winEnd != v.size(); ++winEnd) {
        // Add new element coming into the sliding window/subarray
        winSum += v[winEnd];
        // Keep on adding elements to window/subarray till
        // at least one subarray worth of elements are processed
        if (winEnd >= (subArrSz - 1)) {
            // Append average of sliding window/subarray to result
            avgV[winStart] = winSum / subArrSz;
            // Slide the window forward to next subarray, subtract element 
            // going out of window from subarray sum
            winSum -= v[winStart];
            ++winStart;
        }
    }
    return avgV;
}
