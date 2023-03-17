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
using std::max;
using std::domain_error;

// Statics, typedefs, globals
typedef string::size_type strSzT;

string::size_type
String::longestSubStrLenWithKDistinctChars(const string& s, unsigned k) {
    if (s.empty()) {
        throw domain_error("Error! Empty input string!");
    }
    if (0 == k || k > s.size()) {
        throw domain_error("Error! Invalid num distinct chars!");
    }

    // Hash table for tracking frequency count of chars in substring
    // formed by sliding window
    unordered_map<char, unsigned> charFreqTbl;
    strSzT maxLen = 0;
    strSzT winStartIdx = 0;
    // Substring extends from [winStartIdx, winEndIdx] as delimited by sliding
    // window. Keep adding chars from right end of string to substring/sliding
    // window one at a time
    for (strSzT winEndIdx = 0; winEndIdx != s.size(); ++winEndIdx) {
        // Add new character to sliding window and update its frequency count
        char rightMostChar = s[winEndIdx];
        charFreqTbl[rightMostChar]++;
        // Number of distinct chars in sliding window [winStartIdx, winEndIdx]
        // has exceeded permissible value 'k'. Shrink window from left till
        // it is back to permissible value
        while (charFreqTbl.size() > k) {
            // Update frequency count of leftmost character to account
            // for shrinking from left.
            char leftMostChar = s[winStartIdx];
            charFreqTbl[leftMostChar]--;
            if (charFreqTbl[leftMostChar] == 0) {
                charFreqTbl.erase(leftMostChar);
            }
            // Advance/shrink sliding window/subarray from left
            ++winStartIdx;
        }

        // Update maximum length once the sliding window subarray has
        // requisite num of distinct chars
        if (charFreqTbl.size() == k) {
            maxLen = max(maxLen, winEndIdx - winStartIdx + 1);
        }
    }

    return maxLen;
}
