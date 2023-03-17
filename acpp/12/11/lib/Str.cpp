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

Str::Str(const char *cp) :
    vdata(cp, cp + strlen(cp)), strDataBuf(NULL), dataBuf(NULL) {
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

Str
operator+(const Str& lhs, const Str& rhs) {
    Str result = lhs;
    result += rhs;
    return result;
}

Str
operator+(const char* lhs, const Str& rhs) {
    Str result(lhs, lhs + strlen(lhs));
    //std::copy(lhs, lhs + strlen(lhs), std::back_inserter(result.vdata));
    result += rhs;
    return result;
}

Str
operator+(const Str& lhs, const char* rhs) {
    Str result = lhs;
    std::copy(rhs, rhs + strlen(rhs), std::back_inserter(result.vdata));
    return result;
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

// (In)equality operators
bool
operator==(const Str& lhs, const Str& rhs) {
    return (strCmp(lhs, rhs) == 0);
}

bool
operator!=(const Str& lhs, const Str& rhs) {
    return !(lhs == rhs);
}

// getline function
std::istream&
getline(std::istream& is, Str& s) {
    // Clear the data in the string
    s.vdata.clear();

    // Keep reading the characters from the input stream and
    // append it to the string till end of line or end of
    // file is reached. 
    if (is) {
        char c;
        while (is.get(c) && c != '\n') {
            s.vdata.push_back(c);
        }
    }
    return is;
}
