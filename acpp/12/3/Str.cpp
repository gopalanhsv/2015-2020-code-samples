// System headers
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <cstring>

// Local includes
#include "Str.h"

// Using declarations

// Typedefs

Str::Str(const char *cp) : strDataBuf(NULL), dataBuf(NULL) {
    std::copy(cp, cp + strlen(cp), std::back_inserter(vdata));
}

Str::~Str() {
    delete strDataBuf;
    delete dataBuf;
}

Str&
Str::operator+=(const Str& rhs) {
    std::copy(rhs.vdata.begin(), rhs.vdata.end(), std::back_inserter(vdata));
}

const char*
Str::c_str() const {
    // Delete the contents of old buffer
    delete strDataBuf;
    // Allocate new buffer to hold null terminated underlying string
    strDataBuf = new char[vdata.size() + 1];
    // Copy the underlying string contents to allocated buffer
    for (size_type i = 0; i != size(); ++i) {
        strDataBuf[i] = vdata[i];
    }
    // Add the null termination
    strDataBuf[vdata.size()] = '\0';
    return strDataBuf;
}

const char*
Str::data() const {
    // Delete the contents of old buffer
    delete dataBuf;
    // Allocate new buffer to hold underlying string
    dataBuf = new char[vdata.size() + 1];
    // Copy the underlying string contents to allocated buffer
    for (size_type i = 0; i != size(); ++i) {
        dataBuf[i] = vdata[i];
    }
    return dataBuf;
}

void
Str::copy(char* buf, size_t n) const {
    // Copy the underlying string contents to specified buffer
    for (size_t i = 0; i != n; ++i) {
        buf[i] = vdata[i];
    }
}

Str
operator+(const Str& lhs, const Str& rhs) {
    Str result = lhs;
    result += rhs;
    return result;
}

std::istream&
operator>>(std::istream& is, Str& s) {
    // Clear existing vdata
    s.vdata.clear();

    // Read and ignore leading whitespaces
    char c;
    while (is.get(c) && isspace(c));

    // If end of input is not reached and a valid char at input
    if (is) {
        // Read chars into string vdata till a whitespace or end
        // of input encountered
        do {
            s.vdata.push_back(c);
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

// Helper for relational and (in)equality operators
static int
strCmp(const Str& lhs, const Str& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str());
}

// Relational operators
bool
operator<(const Str& lhs, const Str& rhs) {
    return (strCmp(lhs, rhs) < 0);
}

bool
operator<=(const Str& lhs, const Str& rhs) {
    return (strCmp(lhs, rhs) <= 0);
}

bool
operator>(const Str& lhs, const Str& rhs) {
    return (strCmp(lhs, rhs) > 0);
}

bool
operator>=(const Str& lhs, const Str& rhs) {
    return (strCmp(lhs, rhs) >= 0);
}
