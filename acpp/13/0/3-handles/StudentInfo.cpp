// System headers
#include <iostream>
#include <string>
#include <stdexcept>

// Local includes
#include "Core.h"
#include "Grad.h"
#include "StudentInfo.h"

// Using declarations
using std::istream;
using std::string;
using std::runtime_error;

// Statics, globals, typedefs

// Constructors
StudentInfo::StudentInfo(const StudentInfo& rhs) {
    cp = (rhs.cp) ? rhs.cp->clone() : NULL;
}

StudentInfo::~StudentInfo() {
    delete cp;
}

// Assignment operator
StudentInfo&
StudentInfo::operator=(const StudentInfo& rhs) {
    if (this != &rhs) {
        delete cp;
        cp = (rhs.cp) ? rhs.cp->clone() : NULL;
    }
    return *this;
}

// Interface functions
std::istream&
StudentInfo::read(std::istream& is) {
    char ch;
    is >> ch;
    if ('U' == ch) {
        cp = new Core(is);
    } else if ('G' == ch) {
        cp = new Grad(is);
    }
    return is;
}

double
StudentInfo::grade() const {
    if (cp) {
        return cp->grade();
    } else {
        throw runtime_error("Error! Invalid StudentInfo handle! Exiting...!");
    }
}

string
StudentInfo::name() const {
    if (cp) {
        return cp->name();
    } else {
        throw runtime_error("Error! Invalid StudentInfo handle! Exiting...!");
    }
}

bool
StudentInfo::compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
}
