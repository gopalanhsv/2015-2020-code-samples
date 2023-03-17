#include <string>
#include <cctype>

using std::string;

bool
isPalindrome(const string& s) {
    // Indices to traverse string from left and right
    string::size_type l, r;
    // Strip the string of all non-alphabetic chars
    // and convert to upper case
    string stripStr;
    l = 0;
    while (l != s.size()) {
        if (isalpha(s[l])) {
            stripStr += toupper(s[l]);
        }
        ++l;
    }
    // Non alphabetic string => non palindrome
    if (0 == stripStr.size()) {
        return false;
    }

    // Check the string character by character till the indices
    // do not cross over
    l = 0;
    r = stripStr.size() - 1;
    while (l < r) {
        // Test if the char pointed by left and right index are unequal
        if (stripStr[l] != stripStr[r]) {
            return false;
        }

        // Increment left index
        // Decrement right index
        ++l;
        --r;
    }

    return true;
} 
