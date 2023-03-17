// System headers
#include <cctype>

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "split.h"

Vec<Str>
split(const Str& s) {
    Vec<Str> ret;
    Str::size_type i = 0;
    
    // Invariant : While all characters of the string are not examined
    while (i != s.size()) {

        // Ignore leading blanks/whitespaces
        // Invariant : Range [original i, current i) contains
        // only whitespaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        Str::size_type j = i;
        // Find the end of current word/i.e the first whitespace
        // post the current word
        // Invariant : Range [original j, current j) delimits current word
        // i.e. has no whitespaces
        while (j != s.size() && !isspace(s[j]))
            ++j;

        // A new word is found
        if (i != j) {
            // Add the current word delimited by index [i, j) to vector 
            ret.push_back(Str(s.begin() + i, s.begin() + j));
            i = j;
        }

    }

    return ret;
}
