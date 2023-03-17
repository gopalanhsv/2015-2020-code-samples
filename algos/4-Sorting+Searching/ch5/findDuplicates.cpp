// System headers
#include <vector>
#include <unordered_map>
#include <stdexcept>

// Local includes
#include "findDuplicates.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::domain_error;

// Statics, globals, typedefs

vector<int>
findDuplicates(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Maintain a frequency table of vector elements
    // mapped to their respective occurrence counts
    unordered_map<int, int> frequencyTbl;

    // Iterate over the vector and update the frequency table
    for (auto elem: v) {
        frequencyTbl[elem] += 1;
    }

    vector<int> dups;
    // Iterate over the frequency table and determine the elements
    // which had multiple occurences. Return the same
    for (auto tblElem : frequencyTbl) {
        if (tblElem.second > 1) {
            dups.push_back(tblElem.first);
        }
    }

    return dups;
}
