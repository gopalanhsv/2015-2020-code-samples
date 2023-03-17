// System headers
#include <vector>
#include <unordered_set>
#include <stdexcept>

// Local includes
#include "isSubset.h"

// Using declarations
using std::vector;
using std::unordered_multiset;
using std::domain_error;

bool
is2ndVecSubsetof1st(const vector<int>& v1, const vector<int>& v2) {
    if (v1.empty() || v2.empty()) {
        throw domain_error("Error! Empty input vectors!");
    }

    typedef vector<int>::size_type vecSzT;

    // Add all contents of v1 to hash table
    unordered_multiset<int> hashTbl;
    for (vecSzT i = 0; i != v1.size(); ++i) {
        hashTbl.insert(v1[i]);
    }

    // Iterate over all elements of v2. Check for presence of
    // each element of v2 in hash table containing v1 elements.
    // Absence of any element of v2 in v2 => v2 is not subset of v1
    for (vecSzT i = 0; i != v2.size(); ++i) {
        if (hashTbl.find(v2[i]) == hashTbl.end()) {
            return false;
        }
    }

    return true;
}
