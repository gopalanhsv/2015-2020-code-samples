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

// Statics, typedefs, globals

StudentInfo::StudentInfo(std::istream& is) : rhc(NULL) {
    read(is);
}

istream&
StudentInfo::read(std::istream& is) {
    char ch;
    is >> ch;

    // Create a temporary object using RefHandle<T>::RefHandle<T>(T*)
    // Deletion of the old RefHandle object happens in RefHandle<T> copy cons
    // Assign it to the (un)bound to *this using RefHandle<T>::operator=
    if ('U' == ch) {
        rhc = new Core(is);
    } else if ('G' == ch) {
        rhc = new Grad(is);
    }

    return is;
}

string
StudentInfo::name() const {
    if (rhc) {
        return rhc->name();
    } else {
        throw runtime_error(
            "Error! Uninitialized student in StudentInfo::name()!");
    }
}

double
StudentInfo::grade() const {
    if (rhc) {
        return rhc->grade();
    } else {
        throw runtime_error(
            "Error! Uninitialized student in StudentInfo::grade()!");
    }
}

bool
StudentInfo::compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
}

