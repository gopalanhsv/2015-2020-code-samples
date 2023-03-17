// System headers
#include <vector>
#include <string>
#include <algorithm>

// Local includes
#include "lpsLen.h"

// Using declarations
using std::vector;
using std::string;
using std::max;

// Statics, typedefs, globals

// Find the length of the longest palindromic subsequence for the
// substring s[sIdx, eIdx], i.e string delimited by indices sIdx & eIdx
strSzT
lpsLenBruteForceRec(const string& s, strSzT sIdx, strSzT eIdx) {
    // Entire string has been examined
    if (sIdx > eIdx) {
        return 0;
    }

    // Single char string is always a palindrome
    if (sIdx == eIdx) {
        return 1;
    }

    if (s[sIdx] == s[eIdx]) {
        // Beginning and last characters of substring match form a
        // palindromic subsequence.
        // LPS would be these 2 chars and LPS of given substring with
        // the chars skipped
        return 2 + lpsLenBruteForceRec(s, sIdx + 1, eIdx - 1);
    }

    // Beginning and last characters of substring dont match
    // LPS would be max of the LPS of the 2 substrings formed by skipping
    // a char from the beginning and the end
    return max(lpsLenBruteForceRec(s, sIdx, eIdx - 1),
        lpsLenBruteForceRec(s, sIdx + 1, eIdx));
}

// Find the length of the longest palindromic
// subsequence for the given string
strSzT
lpsLenBruteForce(const string& s) {
    // Base case of null/single char string
    if (s.empty() || 1 == s.size()) {
        return s.size();
    }

    return lpsLenBruteForceRec(s, 0, s.size() - 1);
}

// Find the length of the longest palindromic subsequence for the
// substring s[sIdx, eIdx], i.e string delimited by indices sIdx & eIdx
strSzT
lpsLenDpMemoizationRec(const string& s,
    strSzT sIdx, strSzT eIdx, vector<vector<int> >& lpsLenTbl) {

    // Entire string has been examined
    if (sIdx > eIdx) {
        return 0;
    }

    // Single char string is always a palindrome
    if (sIdx == eIdx) {
        return 1;
    }

    // If the LPS length lookup table has a valid entry for the given
    // return the same
    if (-1 != lpsLenTbl[sIdx][eIdx]) {
        return lpsLenTbl[sIdx][eIdx];
    }

    if (s[sIdx] == s[eIdx]) {
        // Beginning and last characters of substring match form a
        // palindromic subsequence.
        // LPS would be these 2 chars and LPS of given substring with
        // the chars skipped
        lpsLenTbl[sIdx][eIdx] =
            2 + lpsLenDpMemoizationRec(s, sIdx + 1, eIdx - 1, lpsLenTbl);
    } else {
        // Beginning and last characters of substring dont match
        // LPS would be max of the LPS of the 2 substrings formed by skipping
        // a char from the beginning and the end
        lpsLenTbl[sIdx][eIdx] = max(
            lpsLenDpMemoizationRec(s, sIdx, eIdx - 1, lpsLenTbl),
            lpsLenDpMemoizationRec(s, sIdx + 1, eIdx, lpsLenTbl));
    }

    return lpsLenTbl[sIdx][eIdx];
}

// Find the length of the longest palindromic
// subsequence for the given string
strSzT
lpsLenDpMemoization(const string& s) {
    // Base case of null/single char string
    if (s.empty() || 1 == s.size()) {
        return s.size();
    }

    // 2-D array table mapping the various substrings of given string
    // to the length of LPS formed by the substrings. Table entry
    // [sIdx, eIdx] given the length of the LPS formed by the 
    // substring s[sIdx, eIdx]
    vector<vector<int> >
        lpsLenTbl(s.size(), vector<int>(s.size(), -1));

    return lpsLenDpMemoizationRec(s, 0, s.size() - 1, lpsLenTbl);
}

// Find the length of the longest palindromic
// subsequence for the given string
strSzT
lpsLenDpTabulation(const string& s) {

    // Base case of null/single char string
    if (s.empty() || 1 == s.size()) {
        return s.size();
    }

    // 2-D array table mapping the various substrings of given string
    // to the length of LPS formed by the substrings. Table entry
    // [sIdx, eIdx] given the length of the LPS formed by the 
    // substring s[sIdx, eIdx]
    vector<vector<int> >
        lpsLenTbl(s.size(), vector<int>(s.size(), 0));

    // All substrings of single length characters are palindromes of length 1
    for (vector<vector<int> >::size_type i = 0; i != s.size(); ++i) {
        lpsLenTbl[i][i] = 1;
    }

    typedef vector<vector<int> >::size_type vecVecSzT;
    typedef vector<int>::size_type vecSzT;

    // Consider all possible subsequences of the given string with 
    // start index always lesser than end index. 
    // Start index commences from second last char and moves backwards
    for (vecVecSzT sIdx = s.size() - 2; sIdx >= 0; --sIdx) {
        // End index commences next to start index char and moves forward
        for (vecSzT eIdx = sIdx + 1; eIdx < s.size(); ++eIdx) {
            if (s[sIdx] == s[eIdx]) {
                // Beginning and last characters of substring match form a
                // palindromic subsequence.
                // LPS would be these 2 chars and LPS of given substring with
                // the chars skipped
                lpsLenTbl[sIdx][eIdx] = 2 + lpsLenTbl[sIdx + 1][eIdx - 1];
            } else {
                // Beginning and last characters of substring dont match
                // LPS would be max of the LPS of the 2 substrings formed
                // by skipping a char from the beginning and the end
                lpsLenTbl[sIdx][eIdx] =
                    max(lpsLenTbl[sIdx][eIdx - 1], lpsLenTbl[sIdx + 1][eIdx]);
            }
        }

        if (0 == sIdx) {
            break;
        }
    }

    return lpsLenTbl[0][s.size() - 1];
}
