// System includes
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// Local includes
#include "split.h"

// Using declarations
using std::string;
using std::vector;
using std::find_if;

bool
isSpace(char c) {
    return isspace(c);
}

bool
notSpace(char c) {
    return !isspace(c);
}

// Splits an input string into its contituent words
vector<string>
split(const string& s) {

    typedef string::const_iterator strIterT;
    vector<string> ret;
    strIterT b = s.begin();
    strIterT i, j;
    i = b;

    // Traverse the entire string looking for constituent words
    while (i != s.end()) {
        // Ignore leading blanks and find start of next word
        i = find_if(i, s.end(), notSpace);

        // Find the end of current word
        j = find_if(i, s.end(), isSpace);

        // A constituent word has been found, add to return vector
        if (i != j) {
            ret.push_back(string(i, j));
        }

        i = j;
    }

    return ret;
}
