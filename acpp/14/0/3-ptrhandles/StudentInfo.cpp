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

StudentInfo::StudentInfo(std::istream& is) : pc(NULL) {
    read(is);
}

istream&
StudentInfo::read(std::istream& is) {
    char ch;
    is >> ch;

    // Create a temporary object using Ptr<T>::Ptr<T>(T*)
    // Deletion of the old RefHandle object happens in Ptr<T> copy cons
    // Assign it to the (un)bound to *this using Ptr<T>::operator=
    if ('U' == ch) {
        pc = new Core(is);
    } else if ('G' == ch) {
        pc = new Grad(is);
    }

    return is;
}

string
StudentInfo::name() const {
    if (pc) {
        return pc->name();
    } else {
        throw runtime_error(
            "Error! Uninitialized student in StudentInfo::name()!");
    }
}

double
StudentInfo::grade() const {
    if (pc) {
        return pc->grade();
    } else {
        throw runtime_error(
            "Error! Uninitialized student in StudentInfo::grade()!");
    }
}

bool
StudentInfo::compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
}

