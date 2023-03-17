// System headers
#include <vector>
#include <unordered_set>
#include <stdexcept>

// Local includes
#include "areDisjointSets.h"

// Using declarations
using std::vector;
using std::unordered_multiset;
using std::domain_error;

bool
areDisjointSets(const vector<int>& s1, const vector<int>& s2) {
    if (s1.empty() || s2.empty()) {
        throw domain_error("Error! Empty input vectors!");
    }

    typedef vector<int>::size_type vecSzT;

    // Add all contents of s1 to hash table
    unordered_multiset<int> hashTbl;
    for (vecSzT i = 0; i != s1.size(); ++i) {
        hashTbl.insert(s1[i]);
    }

    // Iterate over all elements of s2. Check for presence of
    // each element of s2 in hash table containing s1 elements.
    // Presence of any element of s2 in s1 => s2 and s1 are not disjoint
    for (vecSzT i = 0; i != s2.size(); ++i) {
        if (hashTbl.find(s2[i]) != hashTbl.end()) {
            return false;
        }
    }

    return true;
}
