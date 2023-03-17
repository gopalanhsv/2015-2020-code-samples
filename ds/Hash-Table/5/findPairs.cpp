// System headers
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <utility>

// Local includes
#include "findPairs.h"

// Using declarations
using std::domain_error;
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;

// Statics, typedefs, globals

vector<pair<int, int> >
findPairsWithSameSum(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;
    unordered_map<int, pair<int, int> > sumToPairHashTbl;
    // Iterate over all pairs possible in the input vector
    for (vecSzT i = 0; i != v.size(); ++i) {
        for (vecSzT j = i + 1; j != v.size(); ++j) {
            // Conpute sum of pairs
            int pairSum = v[i] + v[j];

            // Check if the pair sum already exists in the hash table
            if (sumToPairHashTbl.find(pairSum) != sumToPairHashTbl.end()) {
                // Pair sum already exists in the hash table
                // Implies that current pair and pairs in hash table have
                // same sum
                const pair<int, int>& hTblPair = sumToPairHashTbl[pairSum];
                vector<pair<int, int> > sameSumPairVec;
                sameSumPairVec.push_back(hTblPair);
                sameSumPairVec.push_back(make_pair(v[i], v[j]));
                return sameSumPairVec;
            } else {
                // Pair sum not in the hash table. So the current pair
                // yet to be seen. Insert the pairs against the pair sum in
                // hash table
                sumToPairHashTbl[pairSum] = make_pair(v[i], v[j]);
            }
        }
    }

    // No same sum pair found
    return vector<pair<int, int> >();
}
