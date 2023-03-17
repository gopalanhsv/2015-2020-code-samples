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
    std::cerr << "Core::Core(istream&)" << std::endl;
    read(is);
}

istream&
Core::read(istream& is) {
    std::cerr << "Core::read(istream&)" << std::endl;
    readCommon(is);
    readHomework(is, homework);
    return is;
}

double
Core::grade() const {
    std::cerr << "Core::grade()" << std::endl;
    return ::grade(midterm, final, homework);
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
compareCorePtrs(const Core* cp1, const Core* cp2) {
    return cp1->name() < cp2->name();
}
