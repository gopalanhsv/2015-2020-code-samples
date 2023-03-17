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
    friend Str operator+(const char*, const Str&);
    friend Str operator+(const Str&, const char*);
    friend std::istream& getline(std::istream&, Str&);

public:
    // Typedefs
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;

    // Constructors
    Str() : vdata(), strDataBuf(NULL), dataBuf(NULL) {}
    Str(size_type n, char c) : vdata(n, c), strDataBuf(NULL), dataBuf(NULL) {}
    Str(const char* cp);
    template<typename In> Str(In b, In e);

    // Destructor
    ~Str();

    // Index operator
    char& operator[](size_type i) { return vdata[i]; }
    const char& operator[] (size_type i) const { return vdata[i]; }

    // operator+=
    Str& operator+=(const Str& rhs);

    // Size
    size_type size() const { return vdata.size(); }

    // Iterators
    iterator begin() { return vdata.begin(); }
    iterator end() { return vdata.end(); }
    const_iterator begin() const { return vdata.begin(); }
    const_iterator end() const { return vdata.end(); }

    // Typeconversion operator
    operator bool() const { return size() != 0; }; 

    // Fns for returning the underlying char of the Str
    // in a temporary buf
    const char* c_str() const;
    const char* data() const;
    void copy(char*, size_type) const;

private:
    // String implemented as a Vec of chars
    Vec<char> vdata;
    // Used by c_str() and data() fns to return a copy
    // of the strings' underlying char array data
    mutable char *strDataBuf;
    mutable char *dataBuf;
};

// Concatenation Operator
Str operator+(const Str& lhs, const Str& rhs);
Str operator+(const char* lhs, const Str& rhs);
Str operator+(const Str& lhs, const char* rhs);

// Stream operators
std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

// Relational operators
bool operator<(const Str& lhs, const Str& rhs);
bool operator<=(const Str& lhs, const Str& rhs);
bool operator>(const Str& lhs, const Str& rhs);
bool operator>=(const Str& lhs, const Str& rhs);

// (In)Equality operators
bool operator!=(const Str& lhs, const Str& rhs);
bool operator==(const Str& lhs, const Str& rhs);

// getline function
std::istream& getline(std::istream&, Str&);

// Template function implementations
template<typename In>
Str::Str(In b, In e) : strDataBuf(NULL), dataBuf(NULL) {
    std::copy(b, e, std::back_inserter(vdata));
}

#endif /* _STR_H_ */
