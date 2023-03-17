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

StudentInfo::StudentInfo(): computedGrade(0), validGrade(false) {
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
    double midterm, final;
    in >> n >> midterm >> final;
    // Read homework grades
    vector<double> homework;
    readHw(in, homework);
    // Grading valid only if homework was submitted
    if (!homework.empty()) {
        validGrade = true;
    	computedGrade = ::grade(midterm, final, homework); 
    } else {
        validGrade = false;
    	computedGrade = 0;
    }
    return in;
}

double
StudentInfo::grade() const {
    return computedGrade;
}

bool
StudentInfo::valid() const {
    return validGrade;
}

bool
compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
}
