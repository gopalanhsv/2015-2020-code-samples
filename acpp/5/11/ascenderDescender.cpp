#include <string>
#include <cctype>
#include "ascenderDescender.h"

using std::string;

bool
isAscenderOrDescender(char c) {
    if (!isalpha(c) || !islower(c))
        return false;

    if (c == 'b' || c == 'd' || c == 'f' ||
        c == 'h' || c == 'k' || c == 'l' || c == 't' ||
        c == 'g' || c == 'j' || c == 'p' || c == 'q' || c == 'y') {
        return true;
    }
    return false;
}

bool
hasAscendersOrDescenders(const string& s) {
    string::const_iterator iter = s.begin();
    string::const_iterator endIter = s.end();
    for (; iter != endIter; ++iter) {
        if (isAscenderOrDescender(*iter)) {
            return true;
        }
    }

    return false;
}
