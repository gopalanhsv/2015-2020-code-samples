// System headers
#include <string>
#include <vector>
#include <algorithm>

// Local includes
#include "scsLen.h"

// Using declarations
using std::vector;
using std::string;
using std::min;

// Statics, typedefs, globals
typedef string::size_type strSzT;

// Finds the shortest common supersequence of the 2 strings
// s1[0, i1) and s2[0, i2)
strSzT
scsLenBruteForceRec(const string& s1, strSzT i1,
    const string& s2, strSzT i2) {
    // Base case, one of the two substrings empty, SCS
    // would be the length of other string
    if (0 == i1) {
        return i2;
    }
    if (0 == i2) {
        return i1;
    }

    strSzT scsLen;
    if (s1[i1 - 1] == s2[i2 - 1]) {
        // Last characters of the two input strings match
        // SCS len would be 1 + SCS len of the two strings
        // with last char skipped for each
        scsLen = 1 + scsLenBruteForceRec(s1, i1 - 1, s2, i2 - 1);
    } else {
        // Last characters of the two input strings dont match
        // SCS len would be 1 + min of the following two SCS lengths
        // (one string taken fully with last char in other string skipped)
        // 1. s1[0, i1 - 1) with s2[0, i2)
        // 2. s1[0, i1) with s2[0, i2 - 1)
        scsLen = 1 + min(
            scsLenBruteForceRec(s1, i1 - 1, s2, i2),
            scsLenBruteForceRec(s1, i1, s2, i2 - 1));
    }

    return scsLen;
}

// Finds the shortest common supersequence of specified 2 strings
strSzT
scsLenBruteForce(const string& s1, const string& s2) {
    return scsLenBruteForceRec(s1, s1.size(), s2, s2.size());
}

// Finds the shortest common supersequence of the 2 strings
// s1[0, i1) and s2[0, i2)
strSzT
scsLenDPMemoizationRec(const string& s1, strSzT i1,
    const string& s2, strSzT i2, vector<vector<int> >& scsLenTbl) {

    // Base case, one of the two substrings empty, SCS len
    // would be the length of other string
    if (0 == i1) {
        return i2;
    }
    if (0 == i2) {
        return i1;
    }

    // Check up the SCS len lookup table for the given substring and
    // return the value if valid
    if (-1 != scsLenTbl[i1][i2]) {
        return scsLenTbl[i1][i2];
    }

    strSzT scsLen;
    if (s1[i1 - 1] == s2[i2 - 1]) {
        // Last characters of the two input strings match
        // SCS len would be 1 + SCS len of the two strings
        // with last char skipped for each
        scsLen = 1 + scsLenBruteForceRec(s1, i1 - 1, s2, i2 - 1);
    } else {
        // Last characters of the two input strings dont match
        // SCS len would be 1 + min of the following two SCS lengths
        // (one string taken fully with last char in other string skipped)
        // 1. s1[0, i1 - 1) with s2[0, i2)
        // 2. s1[0, i1) with s2[0, i2 - 1)
        scsLen = 1 + min(
            scsLenBruteForceRec(s1, i1 - 1, s2, i2),
            scsLenBruteForceRec(s1, i1, s2, i2 - 1));
    }

    // Update the SCS len lookup table for given substrings
    scsLenTbl[i1][i2] = scsLen;

    return scsLen;
}

// Finds the shortest common supersequence of specified 2 strings
strSzT
scsLenDPMemoization(const string& s1, const string& s2) {
    // A 2-D array which maps substrings of given 2 strings to the SCS
    // length between the substrings. An entry at [i, j] gives the SCS
    // len of substrings s1[0, i) and s2[0, j)
    vector<vector<int> >
        scsLenTbl(s1.size() + 1, vector<int>(s2.size() + 1, -1));

    return scsLenDPMemoizationRec(s1, s1.size(), s2, s2.size(), scsLenTbl);
}


// Finds the shortest common supersequence of specified 2 strings
strSzT
scsLenDPTabulation(const string& s1, const string& s2) {

    // Base case, one of the two substrings empty, SCS len
    // would be the length of other string
    if (s1.empty()) {
        return s2.size();
    }
    if (s2.empty()) {
        return s1.size();
    }

    // A 2-D array which maps substrings of given 2 strings to the SCS
    // length between the substrings. An entry at [i, j] gives the SCS
    // len of substrings s1[0, i) and s2[0, j). The 0th column and 0th
    // row represents null string/chars
    vector<vector<int> >
        scsLenTbl(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    // Iterate over all the substrings of s1 and s2 and populate the DP table
    for (vector<vector<int> >::size_type i = 0; i <= s1.size(); ++i) {
        for (vector<int>::size_type j = 0; j <= s2.size(); ++j) {
            if (0 == i) {
                // Empty substring, SCS len would be of other substring
                scsLenTbl[0][j] = j;
            } else if (0 == j) {
                // Empty substring, SCS len would be of other substring
                scsLenTbl[i][0] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                // Last characters of the two substrings match
                // SCS len would be 1 + SCS len of the two substrings
                // with last char skipped for each
                scsLenTbl[i][j] = 1 + scsLenTbl[i - 1][j - 1];
            } else {
                // Last characters of the two substrings dont match
                // SCS len would be 1 + min of the following two SCS lengths
                // (one substring taken fully with last char in
                // other substring skipped)
                // 1. s1[0, i - 1) with s2[0, j)
                // 2. s1[0, i) with s2[0, j - 1)
                scsLenTbl[i][j] = 1 +
                    min(scsLenTbl[i][j - 1], scsLenTbl[i - 1][j]);
            }
        }
    }

    return scsLenTbl[s1.size()][s2.size()];
}
