// System headers
#include <string>
#include <vector>
#include <algorithm>

// Local includes
#include "minEditDistance.h"

// Using declarations
using std::string;
using std::vector;

// Statics, typedefs, globals
typedef string::size_type strSzT;

strSzT
min(strSzT a, strSzT b, strSzT c) {
    using std::min;
    return min(a, min(b, c));
}

// Returns the minimum edit distance (levenstein distance to convert a
// the first slen chars of source string s to a target string t of 
// tlen chars via insert, remove, substitution)
strSzT
minEditDistanceBruteForceRec(const string& s, strSzT slen,
    const string& t, strSzT tlen) {
    // Source string is null, insert ops equal to target string length
    // required to get target string
    if (0 == slen) {
        return tlen;
    }
    // Target string is null, removal ops equal to source string length
    // required to get target string
    if (0 == tlen) {
        return slen;
    }

    // If last chars of both source and target strings are identical, recursively
    // compute the edit distance for converting string s[0, slen -1]
    // to string t[0, tlen - 1]; i.e exclude last char from s & t
    if (s[slen - 1] == t[tlen - 1]) {
        return minEditDistanceBruteForceRec(s, slen - 1, t, tlen - 1);
    }

    // Last chars are not identical, then 's' is converted to 't' by
    // 1. Inserting last char
    //    ( s[0, slen - 1] => t[0, tlen - 2] ) + t[tlen - 1]
    // 2. Removing last char
    //    ( s[0, slen - 2] - s[slen - 1] ) => t[0, tlen - 1]
    // 3. Substituting last char
    //    ( s[0, slen - 2] => t[0, tlen - 2] ) + ( s[slen - 1] => t[tlen - 1] )
    // Min edit distance would be 1 (for current operation) + min of the edit
    // distance for coverting remainder source to remainder target string
    return 1 +
        min(minEditDistanceBruteForceRec(s, slen, t, tlen - 1),
            minEditDistanceBruteForceRec(s, slen - 1, t, tlen),
            minEditDistanceBruteForceRec(s, slen - 1, t, tlen - 1));
}

// Returns the minimum edit distance (levenstein distance to convert a
// source string s to a target string t via insert, remove, substititution)
strSzT
minEditDistanceBruteForce(const string& s, const string& t) {
    // If source string is null, target string is created via char
    // insertions equalling the target string size
    if (s.empty()) {
        return t.size();
    }
    // If target string is null, target string is created via char
    // removals equalling the source string size
    if (t.empty()) {
        return s.size();
    }
    return minEditDistanceBruteForceRec(s, s.size(), t, t.size());
}

// Returns the minimum edit distance (levenstein distance to convert a
// the first slen chars of source string s to a target string t of 
// tlen chars via insert, remove, substitution)
strSzT
minEditDistanceDPMemoization(const string& s, strSzT slen,
    const string& t, strSzT tlen, vector<vector<strSzT> >& editDistTbl) {
    // Source string is null, insert ops equal to target string length
    // required to get target string
    if (0 == slen) {
        return tlen;
    }
    // Target string is null, removal ops equal to source string length
    // required to get target string
    if (0 == tlen) {
        return slen;
    }

    // Look up the edit distance table and return if it has a valid entry
    // for given lengths of source and target strings
    if (-1 != editDistTbl[slen][tlen]) {
        return editDistTbl[slen][tlen];
    }

    if (s[slen - 1] == t[tlen - 1]) {
        // Last chars of both source and target strings are identical,
        // recursively compute the edit distance for converting
        // string s[0, slen -1] to string t[0, tlen - 1]; i.e exclude
        // last char from s & t
        editDistTbl[slen][tlen] = 
            minEditDistanceDPMemoization(
                s, slen - 1, t, tlen - 1, editDistTbl);
    } else {
        // Last chars are not identical, then 's' is converted to 't' by
        // 1. Inserting last char
        // ( s[0, slen - 1] => t[0, tlen - 2] ) + t[tlen - 1]
        // 2. Removing last char
        // ( s[0, slen - 2] - s[slen - 1] ) => t[0, tlen - 1]
        // 3. Substituting last char
        // ( s[0, slen - 2] => t[0, tlen - 2] ) + ( s[slen - 1] => t[tlen - 1] )
        // Min edit distance would be 1 (for current operation) +
        // min of the edit distance for coverting remainder source to
        // remainder target string
        editDistTbl[slen][tlen] = 1 + min(
            minEditDistanceDPMemoization(s, slen, t, tlen - 1, editDistTbl),
            minEditDistanceDPMemoization(s, slen - 1, t, tlen, editDistTbl),
            minEditDistanceDPMemoization(s, slen - 1, t, tlen - 1, editDistTbl));
    }

    return editDistTbl[slen][tlen];
}

// Returns the minimum edit distance (levenstein distance to convert a
// source string s to a target string t via insert, remove, substititution)
strSzT
minEditDistanceDPMemoization(const string& s, const string& t) {
    // If source string is null, target string is created via char
    // insertions equalling the target string size
    if (s.empty()) {
        return t.size();
    }
    // If target string is null, target string is created via char
    // removals equalling the source string size
    if (t.empty()) {
        return s.size();
    }

    // Edit distance table which maintains in its entry at [r, c] the
    // edit distance for converting the source string s[1, r] to target
    // string t[1, c]
    vector<vector<strSzT> >
        editDistTbl(s.size() + 1, vector<strSzT>(t.size() + 1, -1) ); 
    // Entry for conversion from source string to null target string
    for (vector<vector<strSzT> >::size_type r = 0; r != s.size() + 1; ++r) {
        editDistTbl[r][0] = r;
    }
    // Entry for conversion from null source string to target string
    for (vector<strSzT>::size_type c = 0; c != t.size() + 1; ++c) {
        editDistTbl[0][c] = c;
    }

    return minEditDistanceDPMemoization(s, s.size(), t, t.size(), editDistTbl);
}

// Returns the minimum edit distance (levenstein distance to convert a
// source string s to a target string t via insert, remove, substititution)
strSzT
minEditDistanceDPTabulation(const string& s, const string& t) {
    // If source string is null, target string is created via char
    // insertions equalling the target string size
    if (s.empty()) {
        return t.size();
    }
    // If target string is null, target string is created via char
    // removals equalling the source string size
    if (t.empty()) {
        return s.size();
    }

    // Edit distance table which maintains in its entry at [r, c] the
    // edit distance for converting the source substring s[1, r] to
    // target substring t[1, c]
    vector<vector<strSzT> >
        editDistTbl(s.size() + 1, vector<strSzT>(t.size() + 1, -1) ); 

    // Iterate over all substrings of source starting from
    // null .. s[0, 0] to s[0, s.size() - 1]
    for (strSzT slen = 0; slen <= s.size(); ++slen) {
        // Iterate over all substrings of target starting from
        // null .. t[0, 0] to t[0, t.size() - 1]
        for (strSzT tlen = 0; tlen <= t.size(); ++tlen) {
            // Determine the edit distance for converting from source
            // substring s[0, slen) to target substring t[0, tlen)
            // and populate the DP edit distance table

            if (0 == slen || 0 == tlen) {
                // Converting null/non-null source string
                // to non-null/null target string via
                // all character insertion/removal
                editDistTbl[slen][tlen] = slen + tlen;
            } else if (s[slen - 1] == t[tlen - 1]) {
                // Last chars of source and target string same
                // So distance is same as that for converting source with
                // with last char skipped to target with last char skipped
                editDistTbl[slen][tlen] = editDistTbl[slen - 1][tlen - 1];
            } else {
                // Last chars of source and target string not same
                // Source is converted to target by either insertion, removal
                // or substitution of last char. Edit distance would be 1
                // (for the current ins, rem, subs operation) in addition to the
                // distance for converting remainder source to remainder target
                editDistTbl[slen][tlen] = 1 + min(
                    editDistTbl[slen][tlen - 1], // insertion
                    editDistTbl[slen - 1][tlen], // removal 
                    editDistTbl[slen - 1][tlen - 1]); // substitution
            }
        }
    }

    return editDistTbl[s.size()][t.size()];
}
