// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "grade.h"
#include "studentInfo.h"

// Using declarations
using std::string;
using std::vector;
using std::istream;

// Typedefs and globals

StudentInfo::StudentInfo(): midterm(0), final(0) {
}

StudentInfo::StudentInfo(std::istream& in) {
    read(in);
}

istream&
readHw(istream& in, vector<double>& homework) {
    if (in) {
        homework.clear();
        double x;
        while (in >> x) {
            homework.push_back(x);
        }
        in.clear();
    }
    return in;
}

istream&
StudentInfo::read(istream& in) {
    // Read name, midterm and final grades
    in >> n >> midterm >> final;
    // Read homework grades
    readHw(in, homework);
    return in;
}

double
StudentInfo::grade() const {
    return ::grade(midterm, final, homework);
}


string
StudentInfo::passFailGrade() const {
    return ::passFailGrade(midterm, final);
}

bool
compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
}
