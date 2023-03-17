// System includes
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// Local includes
#include "findUrl.h"

// Using declarations
using std::string;
using std::vector;
using std::find_if;
using std::find;
using std::search;

using std::string;
using std::string;
using std::string;

// Typedefs
typedef string::const_iterator StrIterT;

bool
notUrlChar(char c) {
    // Characters in additon to alphanumeric which
    // can appear in a valid url
    static const string splUrlChars = "~!@#$%^&*()_+-=:;',.?/";

    // Check whether c can appear in a url and return negated
    return !(
        isalnum(c) ||
        find(splUrlChars.begin(), splUrlChars.end(), c) != splUrlChars.end());
}

StrIterT
urlEnd(StrIterT b, StrIterT e) {
    return find_if(b, e, notUrlChar);
}

StrIterT
urlBeg(StrIterT b, StrIterT e) {
    static const string sep = "://";
    // Search for URL separator in the given string sequence
    // and get iterator to beginning of same
    // i marks location of beginning of url separator
    StrIterT i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {

        // If at least one character exists prior to and after
        // the separator, proceed ahead for checking that the
        // separator forms part of valid url
        if ((i != b) && (i + sep.size() != e)) {

            // Look for beginning of the url (i.e start of protocol-name)
            StrIterT urlBegIter = i;
            while (urlBegIter != b && isalnum(urlBegIter[-1]))
                --urlBegIter;

            // If a valid url character exists prior to location of
            // start of separator and after the separator, a URL
            // is found
            if (urlBegIter != i && !notUrlChar(i[sep.size()])) {
                return urlBegIter;
            }
        }

        // Advance the iterator to beyond the invalid separator to
        // continue search for valid urls
        i += sep.size();
    }
    return i;
}

vector<string>
findUrl(const string& s) {
    StrIterT b = s.begin();
    StrIterT e = s.end();
    vector<string> urlVec;
    // Traverse the entire string till all embedded urls
    // are located
    while (b != e) {

        // Get the beginning of a url (i.e one or more
        // letters followed by ://)
        b = urlBeg(b, e);

        // If a valid url beginning is found
        if (b != e) {

            // Get the end of the url
            StrIterT after = urlEnd(b, e);

            // Store the url string
            if (after != e) {
                urlVec.push_back(string(b, after));
            }

            // Advance to commence search for next embedded url
            b = after;
        }
    }
    return urlVec;
}
