// System headers
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>

// Local includes
#include "Str.h"

// Using declarations

// Typedefs

Str::Str(const char *cp) {
    std::copy(cp, cp + strlen(cp), std::back_inserter(data));
}

Str&
Str::operator+=(const Str& rhs) {
    std::copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data));
}

Str
operator+(const Str& lhs, const Str& rhs) {
    Str result = lhs;
    result += rhs;
    return result;
}

std::istream&
operator>>(std::istream& is, Str& s) {
    // Clear existing data
    s.data.clear();

    // Read and ignore leading whitespaces
    char c;
    while (is.get(c) && isspace(c));

    // If end of input is not reached and a valid char at input
    if (is) {
        // Read chars into string data till a whitespace or end
        // of input encountered
        do {
            s.data.push_back(c);
        } while (is.get(c) && !isspace(c));

        // Push the last read whitespace back into the stream
        if (is) {
            is.unget();
        }
    }

    return is;
}

std::ostream&
operator<<(std::ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i) {
        os << s[i];
    }
    return os;
}
