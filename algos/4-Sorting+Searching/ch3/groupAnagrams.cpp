// System headers
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <cctype>

// Local includes
#include "groupAnagrams.h"

// Using declarations
using std::vector;
using std::map;
using std::string;
using std::sort;
using std::domain_error;

// Statics, globals, typedefs

vector<string>
groupAnagrams(const vector<string>& v) {
    if (!v.size()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<string>::size_type vecSzT;

    map<string, vector<vecSzT> > strKeyToIndexVecTbl;
    // Iterate over the input vector of strings. For each string, sort
    // it to determine its key and populate the string key in the map
    // with value being the vector of indices for each string which maps
    // to the same key (i.e indices of all anagrams)
    for (vecSzT i = 0; i != v.size(); ++i) {
        // Get the string element
        const string& s = v[i];
        string key;
        // Skip white spaces
        for (string::size_type sIdx = 0; sIdx != s.size(); ++sIdx) {
            if (isalpha(s[sIdx])) {
                key += s[sIdx];
            }
        } 
        // Sort it to determine the key
        sort(key.begin(), key.end());
        // Add the string index against its key
        strKeyToIndexVecTbl[key].push_back(i);
    }

    vector<string> anagrams;
    // Map elements get automatically sorted/ordered during insertion
    // And all indices of strings which are anagrams are consolidated
    // in the same vector against a given key
    for (auto mapElem : strKeyToIndexVecTbl) {
        for (auto strIdx : mapElem.second) {
            anagrams.push_back(v[strIdx]);
        }
    }
    return anagrams;
}
