#ifndef _STR_H_
#define _STR_H_

// System headers
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>

// Local includes
#include "Vec.h"

// Using declarations

// Typedefs


class Str {
    // Friend fns
    friend std::istream& operator>>(std::istream&, Str&);

public:
    // Typedefs
    typedef Vec<char>::size_type size_type;

    // Constructors
    Str() {}
    Str(size_type n, char c) : data(n, c) {}
    Str(const char* cp);
    template<typename In> Str(In b, In e);

    // Index operator
    char& operator[](size_type i) { return data[i]; }
    const char& operator[] (size_type i) const { return data[i]; }

    // operator+=
    Str& operator+=(const Str& rhs);

    // Size
    size_type size() const { return data.size(); }

private:
    // String implemented as a Vec of chars
    Vec<char> data;
};

// Concatenation Operator
Str operator+(const Str& lhs, const Str& rhs);
// Stream operators
std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

template<typename In>
Str::Str(In b, In e) {
    std::copy(b, e, std::back_inserter(data));
}

#endif /* _STR_H_ */
