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

string
String::shortestSubstringHavingPattern(const string& s, const string& p) {
    if (s.empty() || p.empty()) {
        throw domain_error("Error! Invalid input string/pattern!");
    }
    if (p.size() > s.size()) {
        throw domain_error("Error! Pattern longer than input string!");
    }

    // Hash table maintaining frequency count of all chars in search pattern
    // Value is signed to account for redundant pattern char matches
    unordered_map<char, int> patternCharFreqTbl;
    for (auto c : p) {
        patternCharFreqTbl[c]++;
    }

    typedef string::size_type strSzT;
    strSzT shortestSubstrLen = s.size() + 1;
    strSzT shortestSubstrIdx;

    // Use a sliding window to select a range [winStart, winEnd] of
    // string and search for the pattern within the range. Extend
    // sliding window by one char at each step
    strSzT winStart = 0;
    unsigned matchedPatternCharCnt = 0;
    for (strSzT winEnd = 0; winEnd != s.size(); ++winEnd) {
        // Rightmost char added to sliding window
        char rtMostChar = s[winEnd];
        if (patternCharFreqTbl.find(rtMostChar) != patternCharFreqTbl.end()) {
            // Righmost char added to window is present in pattern.
            // Account for same by updating search pattern frequency count
            patternCharFreqTbl[rtMostChar]--;
            if (patternCharFreqTbl[rtMostChar] >= 0) {
                // All non redundant occurences of pattern char in
                // sliding window are tracked
                ++matchedPatternCharCnt;
            }
        }

        // Check if all of pattern chars are matched within the sliding
        // window. If yes, shrink the window from left till at least
        // one pattern char gets mis matched
        while (matchedPatternCharCnt == p.size()) {
            // Compute window size
            strSzT winSize = winEnd - winStart + 1;
            // Current window/subarray size is smaller than the previously
            // found shortest substring with pattern. Update shortest substring
            // to current subarray
            if (winSize < shortestSubstrLen) {
                shortestSubstrLen = winSize;
                shortestSubstrIdx = winStart;
            }

            // Shrink window from left one char at a time
            char leftMostChar = s[winStart++];
            if (patternCharFreqTbl.find(leftMostChar) !=
                patternCharFreqTbl.end()) {
                // Left most char prior to shrinking is present in search
                // pattern. Account for same. Redundant occurences of 
                // pattern chars within sliding window are skipped/not
                // accounted since search is for shortest substring
                if (patternCharFreqTbl[leftMostChar] == 0) {
                    --matchedPatternCharCnt;
                }
                // Update search pattern frequency count
                patternCharFreqTbl[leftMostChar]++;
            }
        }
    }

    return ((shortestSubstrLen <= s.size()) ?
        s.substr(shortestSubstrIdx, shortestSubstrLen) : "");
}
