// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "Core.h"
#include "grade.h"

// Using declarations
using std::string;
using std::vector;
using std::istream;

// Typedefs, statics, globals

// Constructors
Core::Core(istream& is) {
    read(is);
}

istream&
Core::read(istream& is) {
    readCommon(is);
    readHomework(is, homework);
    return is;
}

double
Core::grade() const {
    return ::grade(midterm, final, homework);
}

Core*
Core::clone() const {
    return new Core(*this);
}

istream&
Core::readCommon(std::istream& is) {
    // Read name, midterm and final exam grades
    is >> n >> midterm >> final;
}

istream&
Core::readHomework(istream& is, vector<double>& hw) {
    if (is) {
        hw.clear();
        double x;
        while (is >> x) {
            hw.push_back(x);
        }
        is.clear();
    }
    return is;
}

bool
compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}
