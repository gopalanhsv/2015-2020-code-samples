#ifndef _SPLIT_H_
#define _SPLIT_H_

// System headers
#include <string>
#include <cctype>
#include <algorithm>

// Local includes

// Using declarations


// Typedefs

bool
isSpace(char c) {
    return isspace(c);
}

bool
isNotSpace(char c) {
    return !isspace(c);
}

template<class Out>
void
split(const std::string& s, Out dest) {
    // Using declarations done locally due to template
    // fn in order to avoid namespace pollution
    using std::string;
    using std::find_if;

    typedef string::const_iterator StrIterT;
    StrIterT i = s.begin();
    while (i != s.end()) {
        // Ignore leading blanks to get a possible word
        i = find_if(i, s.end(), isNotSpace);

        // Find end of current word
        StrIterT j = find_if(i, s.end(), isSpace);

        // If a word is found, send the word to output
        if (i !=j) {
            *dest++ = string(i , j);
        }

        // Advance the iterator to find next word
        i = j;
    }
}

#endif /* _SPLIT_H_ */
