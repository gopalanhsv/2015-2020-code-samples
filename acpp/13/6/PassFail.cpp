// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "PassFail.h"
#include "grade.h"

// Using declarations
using std::string;
using std::vector;
using std::istream;

// Typedefs, statics, globals

// Constructors
PassFail::PassFail(istream& is) {
    read(is);
}

istream&
PassFail::read(istream& is) {
    readCommon(is);
    readHomework(is, homework);
    return is;
}

double
PassFail::grade() const {
    if (!homework.empty())
        return Core::grade();
    return (midterm + final) / 2.0;
}

bool
PassFail::valid() const {
    return true;
}
