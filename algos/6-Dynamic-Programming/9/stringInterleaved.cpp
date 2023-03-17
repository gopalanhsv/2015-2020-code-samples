// System headers
#include <string>
#include <stdexcept>
#include <map>
#include <vector>

// Local includes
#include "stringInterleaved.h"

// Using declarations
using std::string;
using std::domain_error;
using std::map;
using std::to_string;
using std::vector;

// Statics, typedefs, globals
typedef string::size_type strSzT;

// Returns true if the characters of  substring of strings s1, s2
// commencing from indices i1, i2 respectively can be interleaved in order
// to form the substring of string strToChk commencing from index i3
bool
isStringFormedByInterleavingRec(const string& s1, const string& s2,
    const string& strToChk, strSzT i1, strSzT i2, strSzT i3) {

    // Termination condition : All characters of string strToChk to
    // checked for interleaving have been checked and exhausted 
    if (i3 == strToChk.size()) {
        if (i1 == s1.size() && i2 == s2.size()) {
            // All characters of component string s1/s2 have been
            // examined => strToChk is interleaved
            return true;
        } else {
            // Some characters of component string s1/s2 have yet to
            // be examined, even though strToChk is fully processed
            // => strToChk is not interleaved from s1, s2
            return false;
        }
    }

    bool isInterleaved1 = false, isInterleaved2 = false;
    // First char of substring s1[i1, ...] matches with first char of
    // substring strToChk[i3, ...], recursively check for remaining
    // substrings of s1, s2, strToChk
    if (i1 < s1.size() && s1[i1] == strToChk[i3]) {
        isInterleaved1 =
            isStringFormedByInterleavingRec(
            s1, s2, strToChk, i1 + 1, i2, i3 + 1);
    }

    // First char of substring s2[i2, ...] matches with first char of
    // substring strToChk[i3, ...], recursively check for remaining
    // substrings of s1, s2, strToChk
    if (i2 < s2.size() && s2[i2] == strToChk[i3]) {
        isInterleaved2 =
            isStringFormedByInterleavingRec(
            s1, s2, strToChk, i1, i2 + 1, i3 + 1);
    }

    return isInterleaved1 || isInterleaved2;
}

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingBruteForce(
    const string& s1, const string& s2, const string& strToChk) {
    if (s1.empty() || s2.empty() || strToChk.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Length of the interleaved string should be the sum of
    // the lengths of the component strings
    if (s1.size() + s2.size() != strToChk.size()) {
        return false;
    }

    return isStringFormedByInterleavingRec(s1, s2, strToChk, 0, 0, 0);
}

// Returns true if the characters of  substring of strings s1, s2
// commencing from indices i1, i2 respectively can be interleaved in order
// to form the substring of string strToChk commencing from index i3
bool
isStringFormedByInterleavingRec(const string& s1, const string& s2,
    const string& strToChk, strSzT i1, strSzT i2, strSzT i3,
    map<string, bool>& isSubstringInterleavedTbl) {

    // Termination condition : All characters of string strToChk to
    // checked for interleaving have been checked and exhausted 
    if (i3 == strToChk.size()) {
        if (i1 == s1.size() && i2 == s2.size()) {
            // All characters of component string s1/s2 have been
            // examined => strToChk is interleaved
            return true;
        } else {
            // Some characters of component string s1/s2 have yet to
            // be examined, even though strToChk is fully processed
            // => strToChk is not interleaved from s1, s2
            return false;
        }
    }

    // We have to check if substring s1[i1, ...) and s2[i2, ...) are 
    // interleaved to form the substring strToChk[i3, ...)
    string lookupTableKey =
        to_string(i1) + "-" + to_string(i2) + "-" + to_string(i3);
    // Check entry for the subproblem in the lookup table
    if (isSubstringInterleavedTbl.find(lookupTableKey)
        != isSubstringInterleavedTbl.end()) {
        return isSubstringInterleavedTbl[lookupTableKey];
    }

    bool isInterleaved1 = false, isInterleaved2 = false;
    // First char of substring s1[i1, ...] matches with first char of
    // substring strToChk[i3, ...], recursively check for remaining
    // substrings of s1, s2, strToChk
    if (i1 < s1.size() && s1[i1] == strToChk[i3]) {
        isInterleaved1 =
            isStringFormedByInterleavingRec(
            s1, s2, strToChk, i1 + 1, i2, i3 + 1, isSubstringInterleavedTbl);
    }

    // First char of substring s2[i2, ...] matches with first char of
    // substring strToChk[i3, ...], recursively check for remaining
    // substrings of s1, s2, strToChk
    if (i2 < s2.size() && s2[i2] == strToChk[i3]) {
        isInterleaved2 =
            isStringFormedByInterleavingRec(
            s1, s2, strToChk, i1, i2 + 1, i3 + 1, isSubstringInterleavedTbl);
    }

    // Update the lookup table
    isSubstringInterleavedTbl[lookupTableKey] =
        isInterleaved1 || isInterleaved2;

    return isSubstringInterleavedTbl[lookupTableKey];
}

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingDPMemoization(
    const string& s1, const string& s2, const string& strToChk) {
    if (s1.empty() || s2.empty() || strToChk.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Length of the interleaved string should be the sum of
    // the lengths of the component strings
    if (s1.size() + s2.size() != strToChk.size()) {
        return false;
    }

    // Lookup Table which maintains mapping as to whether a substring
    // of strToChk is interleaved using substrings of s1/s2
    // If the substrings of component strings
    // s1 starting from i1  and s2 starting from i2 are to be checked for
    // interleaving against the substring of strToChk starting from i3
    // the lookup key would the string "i1-i2-i3"
    map<string, bool> isSubstringInterleavedTbl;

    return isStringFormedByInterleavingRec(
        s1, s2, strToChk, 0, 0, 0, isSubstringInterleavedTbl);
}

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingDPTabulation(
    const string& s1, const string& s2, const string& strToChk) {
    if (s1.empty() || s2.empty() || strToChk.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Length of the interleaved string should be the sum of
    // the lengths of the component strings
    if (s1.size() + s2.size() != strToChk.size()) {
        return false;
    }

    typedef vector<bool>::size_type vecSzT;
    typedef vector<vector<bool> >::size_type vecVecSzT;
    // DP Lookup Table which maintains mapping as to whether
    // substring of strToChk is interleaved using substrings of s1/s2
    // Index [r][c] in the lookup table captures whether the substring
    // first r + c characters of strToChk can be interleaved from the
    // first r characters of s1 + the first c characters of s2
    // Row and column index 0 represent null string for s1 and s2
    // respectively
    vector<vector<bool> > strInterleaved(
        s1.size() + 1, vector<bool>(s2.size() + 1, false));

    // Null s2, s1 => matching null strToChk
    strInterleaved[0][0] = true;

    // Null s2, check for match of s1 with strToChk
    for (vecVecSzT i = 1; i <= s1.size(); ++i) {
        if (s1[i - 1] == strToChk[i - 1]) {
            strInterleaved[i][0] = strInterleaved[i - 1][0];
        }
    }

    // Null s1, check for match of s2 with strToChk
    for (vecVecSzT j = 1; j <= s2.size(); ++j) {
        if (s2[j - 1] == strToChk[j - 1]) {
            strInterleaved[0][j] = strInterleaved[0][j - 1];
        }
    }

    // Non null s1 and s2
    for (vecVecSzT i = 1; i <= s1.size(); ++i) {
        for (vecSzT j = 1; j <= s2.size(); ++j) {
            // i th char of s1 matches with current char of strToChk, take
            // value of strings interleaved till i - 1 th char of s1
            bool interleaved = false;
            if (s1[i - 1] == strToChk[i + j - 1]) {
                interleaved = strInterleaved[i - 1][j];
            }
            // j th char of s2 matches with current char of strToChk, take
            // value of strings interleaved till j - 1 th char of s2
            // The ORing is done as one of the current chars of two
            // strings s1, s2 may match with current char of strToChk
            if (s2[j - 1] == strToChk[i + j - 1]) {
                interleaved |= strInterleaved[i][j - 1];
            }
            strInterleaved[i][j] = interleaved;
        }
    }

    return strInterleaved[s1.size()][s2.size()];
}

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingDPOptimized(
    const string& s1, const string& s2, const string& strToChk) {
    if (s1.empty() || s2.empty() || strToChk.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Length of the interleaved string should be the sum of
    // the lengths of the component strings
    if (s1.size() + s2.size() != strToChk.size()) {
        return false;
    }

    // Iterate over all chars of the string to be checked one by one
    // attempting to check if a match occurs with current character of
    // s1 or s2. Advance the current character of matching string
    // to next. If no match occurs in an iteration, it implies an
    // non-interleaved string
    strSzT i = 0;
    strSzT j = 0;
    while (i + j != strToChk.size()) {
        if (s1[i] == strToChk[i + j]) {
            ++i;
        } else if (s2[j] == strToChk[i + j]) {
            ++j;
        } else {
            break;
        }
    }
    return (i + j == strToChk.size());
}
