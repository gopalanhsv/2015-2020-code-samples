// System headers
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "locString.h"

// Using declarations
using std::string;
using std::unordered_map;
using std::domain_error;
using std::max;

// Statics, typedefs, globals
typedef string::size_type strSzT;

string
String::longestSubStringWithNoRepeatChars(const string& s) {
    if (s.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Tracks the location within the string where longest substring with
    // no repeat chars commences and length of same
    strSzT longestSubstrStartIdx = 0;
    strSzT longestSubstrLen = 0;
    // Substring with no repeat chars is determined using a sliding window
    // over string delimited by [winStartIdx, winEndIdx]
    strSzT winStartIdx = 0;
    // Hash table which tracks location of characters within current
    // sliding window
    unordered_map<char, strSzT> winChrLocationTbl;
    // Attempt to extend the window to right by adding more chars from right
    for (strSzT winEndIdx = 0; winEndIdx != s.size(); ++winEndIdx) {
        char rightMostChar = s[winEndIdx];
        // New character to be added to window is already in the current window
        // So shrink/slide the window from left to exclude the previous
        // occurence of rightMostChar
        if (winChrLocationTbl.find(rightMostChar) != winChrLocationTbl.end()) {
            // Shrinking of window from left such as to exclude previous
            // occurence of char to be added to sliding window/no repeat substring
            // in current iteration
            winStartIdx = max(winStartIdx, winChrLocationTbl[rightMostChar] + 1);
        }
        // Update location of current character in hash table
        winChrLocationTbl[rightMostChar] = winEndIdx;
        // Update the longest no repeat char substring length if current
        // no repeat char sliding window length is larger
        strSzT winLen = winEndIdx - winStartIdx + 1;
        if (winLen > longestSubstrLen) {
            longestSubstrLen = winLen;
            longestSubstrStartIdx = winStartIdx;
        }
    }

    return s.substr(longestSubstrStartIdx, longestSubstrLen);
}
