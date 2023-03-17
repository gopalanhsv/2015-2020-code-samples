// System headers
#include <string>
#include <stdexcept>
#include <iostream>

// Local includes
#include "backspaceCompare.h"

// Using declarations
using std::string;
using std::domain_error;

// Statics, typedefs, globals
typedef string::size_type strSzT;

strSzT
BackspaceCompare::getPreviousCharIdxAfterBackspace(
    const string& s, strSzT currIdx) {

    if (0 == currIdx) {
        return currIdx;
    }

    strSzT bkSpcCnt = 0; 
    strSzT chrCnt = 0;

    // Move sequentially backwards from current index in string to front till
    // a non backspace character is reached after adjusting for backspaces
    while (currIdx > 0) {
        (s[currIdx] == '#') ? ++bkSpcCnt: ++chrCnt;
        if (bkSpcCnt + 1 == chrCnt) {
            // First non-backspace char after accounting for backspaces found
            break;
        }
        --currIdx;
    }

    return currIdx;
}

bool
BackspaceCompare::compare(const string& s1, const string& s2) {
    if (s1.empty() || s2.empty()) {
        throw domain_error("Error! Empty input string(s)!");
    }

    // Examine both strings simultaneously from
    // back to front skipping backspace characters
    strSzT i1 = s1.size() - 1, i2 = s2.size() - 1;
    while (true) {
        // Get 1st non-backspace character after adjusting for backspaces
        // for both s1/s2 commencing backwards from current index i1/i2
        i1 = getPreviousCharIdxAfterBackspace(s1, i1);
        i2 = getPreviousCharIdxAfterBackspace(s2, i2);
        // Compare for equality of 1st non-backspace char of s1/s2
        if (s1[i1] != s2[i2]) {
            return false;
        }
        // First character examined for at least one of the strings
        if (0 == i1 || 0 == i2) {
            break;
        }
        // For examining previous characters
        --i1, --i2;
    }

    // True if both string have been fully examined, false otherwise
    return (i1 == i2);
}
