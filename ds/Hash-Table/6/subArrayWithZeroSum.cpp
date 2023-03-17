// System headers
#include <vector>
#include <unordered_set>
#include <stdexcept>

// Local includes
#include "subArrayWithZeroSum.h"

// Using declarations
using std::vector;
using std::unordered_set;
using std::domain_error;

// Statics, typedefs, globals

bool
subArrayWithZeroSumPresent(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Iterate over all elements of the vector sequentially
    // Compute the prefix sum at each element and store in hash table
    int pfxSum = 0;
    unordered_set<int> pfxSumHashTbl;
    for (vector<int>::size_type i = 0; i != v.size(); ++i) {
        pfxSum += v[i];

        // A subarray with zero sum present if :-
        // 1. Current element is 0
        // 2. Current prefix sum is 0
        // 3. Current prefix sum is already stored in hash table (and so
        // was see earlier) => subarray bounded between current index and
        // the earlier index where prefix sum was same is a zero sum one
        if (!v[i] || !pfxSum ||
            pfxSumHashTbl.find(pfxSum) != pfxSumHashTbl.end()) {
            return true;
        }

        // Zero sum subarray yet to be seen. Add prefix sum to hash table
        pfxSumHashTbl.insert(pfxSum);
    }

    return false;
}
