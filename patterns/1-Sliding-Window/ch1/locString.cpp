// System headers
#include <string>
#include <unordered_map>
#include <stdexcept>

// Local includes
#include "locString.h"

// Using declarations
using std::string;
using std::unordered_map;
using std::domain_error;

// Statics, typedefs, globals
typedef string::size_type strSzT;

bool
String::hasPatternPermutation(const string& s, const string& p) {
    if (s.empty() || p.empty()) {
        throw domain_error("Error! Invalid input string/pattern!");
    }
    if (p.size() > s.size()) {
        throw domain_error("Error! Pattern size exceeds string size!");
    }

    // Populate hash table maintaining frequency
    // of each character within pattern
    unordered_map<char, long int> patternCharFreqTbl;
    for (auto c : p) {
        patternCharFreqTbl[c]++;
    }

    strSzT winStart = 0;
    // Counter incremented only if all occurences of a particular search
    // pattern character are fully matched within a substring
    unsigned patternCharMatchCnt = 0;
    // Attempt to determine if pattern exists in sliding window/substring
    // range [winStart, winEnd] under examination. Attempt to extend 
    // sliding window one step to right at each iteration
    for (strSzT winEnd = 0; winEnd != s.size(); ++winEnd) {
        // Extend sliding window one char to right
        char rtMostChar = s[winEnd];
        // Righmost sliding window char if present in search pattern
        if (patternCharFreqTbl.find(rtMostChar) != patternCharFreqTbl.end()) {
            // Decrement frequency count to account for match
            patternCharFreqTbl[rtMostChar]--;
            if (patternCharFreqTbl[rtMostChar] == 0) {
                // All occurences of a particular char in pattern are
                // matched within current substring/sliding window
                ++patternCharMatchCnt;

                // All occurences of all characters in the pattern are
                // matched within current sliding window substring, so
                // a permutation of pattern exists
                if (patternCharMatchCnt == patternCharFreqTbl.size()) {
                    return true;
                }
            }
        }

        // Window size computation
        strSzT winSize = winEnd - winStart + 1;

        // Shrink window from left if window size exceeds pattern length
        if (winSize >= p.size()) {

            // Leftmost char removed from window 
            char leftMostChar = s[winStart++];

            // Leftmost removed char if present in search pattern
            if (patternCharFreqTbl.find(leftMostChar)
                != patternCharFreqTbl.end()) {

                if (patternCharFreqTbl[leftMostChar] == 0) {
                    // All occurences of leftmost char char in pattern are
                    // no longer matched within current sliding window
                    --patternCharMatchCnt;
                }
                // Increment frequency count to account for match character
                // out of sliding window range
                patternCharFreqTbl[leftMostChar]++;
            }
        }
    }

    return false;
}
