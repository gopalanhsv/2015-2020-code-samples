// System headers
#include <string>
#include <iostream>
#include <algorithm>

// Local includes
#include "Grad.h"
#include "grade.h"

// Using declarations
using std::string;
using std::istream;
using std::min;

// Typedefs, statics, globals

// Constructors
Grad::Grad(istream& is) {
    read(is);
}

istream&
Grad::read(istream& is) {
    // Read name, midterm, final grades
    readCommon(is);
    // Read thesis grades
    is >> thesis;
    // Read homework grades
    readHomework(is, homework);
    return is;
}

double
Grad::grade() const {
    return min(thesis, Core::grade());
}
