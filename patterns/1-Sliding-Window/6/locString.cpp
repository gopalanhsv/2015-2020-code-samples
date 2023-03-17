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

unsigned
String::longestSameCharSubtrLenPostCharReplacement(
    const string& s, unsigned maxReplaceCharsNum) {
    if (s.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Use sliding window over string delimited by [winStartIdx, winEndIdx]
    // to get a substring. Keep track of char with max frequency within the
    // window
    // Hash table tracking frequency count of each char within sliding window
    unordered_map<char, unsigned> winChrFreqTbl;
    strSzT winStartIdx = 0;
    char mostFreqChar = '\0';
    strSzT winMostFreqCharCnt = 0;
    strSzT longestSameCharWinLen = 0;
    // Attempt to extend the window range to the right by including one
    // more char at each iteration
    for (strSzT winEndIdx = 0; winEndIdx != s.size(); ++winEndIdx) {
        // Add rightmost char to window and update its frequency count
        char rightMostChar = s[winEndIdx];
        winChrFreqTbl[rightMostChar]++;

        // New right most char is most repeated char within sliding window
        if (winChrFreqTbl[rightMostChar] > winMostFreqCharCnt) {
            winMostFreqCharCnt = winChrFreqTbl[rightMostChar];
            mostFreqChar = rightMostChar;
        }

        strSzT winLen = winEndIdx - winStartIdx + 1;
        // Num of chars which can be replaced within current sliding window
        // to make all chars same as that of the most repeated char has
        // exceeded permissible value
        if (winLen - winMostFreqCharCnt > maxReplaceCharsNum) {
            // Shrink window from left
            char leftMostChar = s[winStartIdx++];
            --winLen;
            winChrFreqTbl[leftMostChar]--;
            // Update frequency of window most repeated char if required
            if (leftMostChar == mostFreqChar) {
                winMostFreqCharCnt--;
            }
        }

        // Update the length of longest repeated char substring
        // to window length if reqd
        longestSameCharWinLen = max(longestSameCharWinLen, winLen);
    }

    return longestSameCharWinLen;
}
