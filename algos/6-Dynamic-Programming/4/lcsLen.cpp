// System headers
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// Local includes
#include "lcsLen.h"

// Using declarations
using std::string;
using std::vector;
using std::max;

// Statics, typedefs, globals
typedef string::size_type strSzT;

// Determine the length of the longest common substring of given
// 2 substrings s1[i1, s1.size()) and s2[i2, s2.size())
strSzT
lcsLenBruteForceRec(const string& s1, strSzT i1,
    const string& s2, strSzT i2, strSzT currLcsLen) {
    // End of one of the strings reached, return 
    if (i1 == s1.size() || i2 == s2.size()) {
        return currLcsLen;
    }

    if (s1[i1] == s2[i2]) {
        // Strings s1 and s2 have a common char at i1/i2 respectively
        // Update the current lcs len to the LCS length for remaining
        // portion of strings advancing by a char in each string
        currLcsLen =
            lcsLenBruteForceRec(s1, i1 + 1, s2, i2 + 1, currLcsLen + 1);
    }

    // Strings s1 and s2 dont have a common char at i1/i2 respectively
    // Commence the search for a LCS again in two parts by advancing a
    // character in one of the strings each
    // (s1[i1+1] onwards with s2[i2] onwards; and s1[i1] onwards with
    // s2[i2+1] onwards). Select the max LCS len computed
    strSzT lcsLen1 = lcsLenBruteForceRec(s1, i1 + 1, s2, i2, 0);
    strSzT lcsLen2 = lcsLenBruteForceRec(s1, i1, s2, i2 + 1, 0);

    return max(currLcsLen, max(lcsLen1, lcsLen2));
}

// Determine the length of the longest common substring of given
// 2 strings
strSzT
longestCommonSubstrLenBruteForce(const string& s1, const string& s2) {
    if (s1.empty() || s2.empty()) {
        // Either of the input strings is null => no common substring
        return 0;
    }

    return lcsLenBruteForceRec(s1, 0, s2, 0, 0);
}

// Determine the length of the longest common substring of given
// 2 substrings s1[0, i1) and s2[0, i2)
int
lcsLenDPMemoizationRec(const string& s1, strSzT i1, const string& s2,
    strSzT i2, int currLcsLen, vector<vector<int> >& lcsLenTbl) {
    // Beginning of one of the strings reached (i.e one of the
    // strings examined completely), return 
    if (i1 == 0 || i2 == 0) {
        return currLcsLen;
    }

    // Check the lookup table and return a result if it has a valid entry
    // for LCS len of given substrings
    if (-1 != lcsLenTbl[i1][i2]) {
        return lcsLenTbl[i1][i2];
    }

    if (s1[i1 - 1] == s2[i2 - 1]) {
        // Strings s1 and s2 have a common char at i1/i2 respectively
        // Update the current lcs len to the LCS length for remaining
        // portion of strings by reducing a char in each string; in order
        // to compute LCS of remaining portion of 2 substrings
        currLcsLen = lcsLenDPMemoizationRec(
            s1, i1 - 1, s2, i2 - 1, currLcsLen + 1, lcsLenTbl);
    }

    // Strings s1 and s2 dont have a common char at i1/i2 respectively
    // Commence the search for a LCS again in two parts by reducing a
    // character in one of the strings each
    // (s1[0, i1-1) with s2[0, i2); and s1[0, i1) with s2[0, i2-1)).
    int lcsLen1 = lcsLenDPMemoizationRec(s1, i1 - 1, s2, i2, 0, lcsLenTbl);
    int lcsLen2 = lcsLenDPMemoizationRec(s1, i1, s2, i2 - 1, 0, lcsLenTbl);

    // Select the max LCS len and populate the lookup table
    lcsLenTbl[i1][i2] = max(currLcsLen, max(lcsLen1, lcsLen2));

    return lcsLenTbl[i1][i2];
}


// Determine the length of the longest common substring of given
// 2 strings
strSzT
longestCommonSubstrLenDPMemoization(const string& s1, const string& s2) {
    if (s1.empty() || s2.empty()) {
        // Either of the input strings is null => no common substring
        return 0;
    }

    // A 2D lookup table which stores the LCS lengths between various
    // substrings of the two given strings s1 & s2. An entry in the lookup
    // table at [r, c] represents the LCS len between the two substrings
    // s1[0, r) and s2[0, c)
    vector<vector<int> >
        lcsLenTbl(s1.size() + 1, vector<int>(s2.size() + 1, -1));

    return lcsLenDPMemoizationRec(s1, s1.size(), s2, s2.size(), 0, lcsLenTbl);
}

// Determine the length of the longest common substring of given
// 2 strings
strSzT
longestCommonSubstrLenDPTabulation(const string& s1, const string& s2) {
    if (s1.empty() || s2.empty()) {
        // Either of the input strings is null => no common substring
        return 0;
    }

    // A 2D lookup table which stores the LCS lengths between various
    // substrings of the two given strings s1 & s2. An entry in the lookup
    // table at [r, c] represents the LCS len between the two substrings
    // s1[0, r) and s2[0, c)
    vector<vector<strSzT> >
        lcsLenTbl(s1.size() + 1, vector<strSzT>(s2.size() + 1, 0));

    strSzT maxLcsLen = 0;
    // Iterate over all substrings of string s1 from
    // s1[0, 0] -> s1[0, s1.size())
    for (vector<vector<strSzT> >::size_type i1 = 1; i1 <= s1.size(); ++i1) {
        // Iterate over all substrings of string s2 from
        // s2[0, 0] -> s2[0, s2.size())
        for (vector<strSzT>::size_type i2 = 1; i2 <= s2.size(); ++i2) {
            // Determine the LCS len between the substrings 
            // s1[0, i1) and s2[0, i2) and populate the DP table
            if (s1[i1 - 1] == s2[i2 - 1]) {
                // Last chars of substrings of s1[0, i1) and s2[0, i2) match
                // so LCS len would be 1 + LCS len of s1/s2 with i1/i2 th char
                // skipped
                lcsLenTbl[i1][i2] = lcsLenTbl[i1 - 1][i2 - 1] + 1;
                maxLcsLen = max(maxLcsLen, lcsLenTbl[i1][i2]);
            } else {
                // Last chars of substrings of s1[0, i1) and s2[0, i2) dont
                // match. So no common subsequence and no LCS. Any entry
                // here will create problems when the two strings start
                // matching again after a mistmatch gap; with total lcs
                // len coming out to be the max match between the strings
                // If one had to find the longest common subsequence instead
                // of longest common string, this has to computed as max of
                // the 3 cells to left, top, and top-left
                lcsLenTbl[i1][i2] = 0; // LCS is 0
            }
        }
    }

    return maxLcsLen;
}

// Determine the length of the longest common substring of given
// 2 strings
strSzT
longestCommonSubstrLenDPTabulationOptimized(
    const string& s1, const string& s2) {
    if (s1.empty() || s2.empty()) {
        // Either of the input strings is null => no common substring
        return 0;
    }

    // A 2D lookup table which stores the LCS lengths between various
    // substrings of the two given strings s1 & s2. An entry in the lookup
    // table at [r, c] represents the LCS len between the two substrings
    // s1[0, r) and s2[0, c)
    // Space optimization using only two rows; as each lookup just refers
    // to the previous row entry while computing. All i1 ops in lookup
    // replaced by i1 ops mod 2.
    vector<vector<strSzT> >
        lcsLenTbl(2, vector<strSzT>(s2.size() + 1, 0));

    strSzT maxLcsLen = 0;
    // Iterate over all substrings of string s1 from
    // s1[0, 0] -> s1[0, s1.size())
    for (vector<vector<strSzT> >::size_type i1 = 1; i1 <= s1.size(); ++i1) {
        // Iterate over all substrings of string s2 from
        // s2[0, 0] -> s2[0, s2.size())
        for (vector<strSzT>::size_type i2 = 1; i2 <= s2.size(); ++i2) {
            // Determine the LCS len between the substrings 
            // s1[0, i1) and s2[0, i2) and populate the DP table
            if (s1[i1 - 1] == s2[i2 - 1]) {
                // Last chars of substrings of s1[0, i1) and s2[0, i2) match
                // so LCS len would be 1 + LCS len of s1/s2 with i1/i2 th char
                // skipped
                lcsLenTbl[i1 % 2][i2] = lcsLenTbl[(i1 - 1) % 2][i2 - 1] + 1;
                maxLcsLen = max(maxLcsLen, lcsLenTbl[i1 % 2][i2]);
            } else {
                // Last chars of substrings of s1[0, i1) and s2[0, i2) dont
                // match. So no common subsequence and no LCS. Any entry
                // here will create problems when the two strings start
                // matching again after a mismatch gap; with total lcs
                // len coming out to be the max match between the strings
                // If one had to find the longest common subsequence instead
                // of longest common string, this has to computed as max of
                // the 3 cells to left, top, and top-left
                lcsLenTbl[i1 % 2][i2] = 0; // LCS is 0
            }
        }
    }

    return maxLcsLen;
}
