// System headers
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stdexcept>
#include <utility>

// Local includes
#include "pairsWithTargetSum.h"

// Using declarations
using std::vector;
using std::unordered_set;
using std::domain_error;
using std::runtime_error;
using std::sort;
using std::pair;
using std::make_pair;

// Statics, typedefs, globals
 
pair<int, int>
PairsWithTargetSum::findPairsTwoPtrs(vector<int> v, int tSum) {
    if (v.size() < 2) {
        throw domain_error("Error! Invalid input vector!");
    }

    // Sort vector elements in ascending order
    sort(v.begin(), v.end());

    typedef vector<int>::size_type vecSzT;
    // Initialize two ptrs left and right to point to vector extremes
    // and move them towards each other restricting the search range
    vecSzT l = 0, r = v.size() - 1;
    while (l < r) {
        if (v[l] == tSum - v[r]) {
            // Pairs indicated by left/right ptrs equals target sum
            return make_pair(v[l], v[r]);
        } else if (v[l] > tSum - v[r]) {
            // Pairs indicated by left/right ptrs exceeds target sum
            // Need to find pair with smaller sum
            --r;
        } else {
            // Pairs indicated by left/right ptrs below target sum
            // Need to find pair with bigger sum
            ++l;
        }
    }

    throw runtime_error("Error! Pair with target sum not found!");
}
 
pair<int, int>
PairsWithTargetSum::findPairsHashing(const vector<int>& v, int tSum) {
    if (v.size() < 2) {
        throw domain_error("Error! Invalid input vector!");
    }

    unordered_set<int> hashTable;
    typedef vector<int>::size_type vecSzT;
    // Iterate over all elements of vector sequentially
    // At each element, check if complementary element (which when added to
    // current element gives target sum) was already seen (hash table lookup)
    for (auto elem : v) {
        // Compute complementary element for target sum
        int compElem = tSum - elem;
        if (hashTable.find(compElem) != hashTable.end()) {
            // Complementary for target sum found in hash table => Pair
            // for target sum found
            return make_pair(compElem, elem);
        } else {
            // Complementary for target sum not found in hash table
            // Add current element to hash table
            hashTable.insert(elem);
        }
    }

    throw runtime_error("Error! Pair with target sum not found!");
}
