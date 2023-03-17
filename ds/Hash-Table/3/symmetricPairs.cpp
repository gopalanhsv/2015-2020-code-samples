// System headers
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <string>

// Local includes
#include "symmetricPairs.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::domain_error;
using std::pair;
using std::make_pair;
using std::string;
using std::to_string;

// Statics, globals, typedefs

string
symmetricPairsInVec(const vector<pair<int, int> >& vp) {
    if (vp.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Hash table mapping a pairs' 2nd member (key) to its 1st (value)
    unordered_map<int, int> hashTbl;
    string symPairs("");
    // Iterate over all elements (pairs) of input vector sequentially
    typedef vector<pair<int, int> >::size_type vecSzT;
    for (vecSzT i = 0; i != vp.size(); ++i) {
        // Get 1st and 2nd members of each pair element
        const pair<int, int>& p = vp[i];
        int f = p.first;
        int s = p.second;

        // Check for an entry in hash table which maps 1st member to 2nd member
        // i.e. an entry f->s
        if (hashTbl.find(f) != hashTbl.end() && hashTbl[f] == s) {
            // Entry f->s exists, implies symmetric pairs {f,s} & {s,f}
            symPairs +=
                "{" + to_string(f) + "," + to_string(s) + "}" +
                "{" + to_string(s) + "," + to_string(f) + "}";
        } else {
            // Entry f->s does not exist, implies no symmetric pair seen for {f,s}
            // Add reverse of current entry f->s to hash table
            hashTbl[s] = f;
        }
    }

    return symPairs;
}
