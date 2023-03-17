// System includes
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

// Local includes
#include "StudentInfo.h"
#include "median.h"

// Using declarations
using std::string;
using std::vector;
using std::istream;
using std::domain_error;

// Reads data for a student in StudentInfo struct from specified
// input stream
istream&
read(istream& in, StudentInfoT& si) {
    if (!in)
        return in;
    // Read student name, midterm and final grades
    in >> si.name >> si.midterm >> si.final;
    // Read homework grades and compute the median
    // of same prior to storing in StudentInfoT
    vector<double> homework;
    if (!readHw(in, homework))
        return in;
    if (0 == homework.size()) {
        throw domain_error(
                "Error! Student has not done any homework! Exiting...!");
    }
    si.homework = median(homework);
    return in;
}

// Reads homework grades into given vector from specified
// input stream
istream&
readHw(istream& in, vector<double>& hw) {
    // Commence reading from given stream only if its not in errored state
    if (in) {
        // Clean up old data from hw vector
        hw.clear();
        // Read homework grades and store into given vector till
        // end-of-file or inappropriate input is encountered
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        // Reset the input stream error condition
        in.clear();
    }
    return in;
}

// Compares 2 StudentInfoT structs on the basis of alphabetical
// ordering
bool
compare(const StudentInfoT& s1, const StudentInfoT& s2) {
    return s1.name < s2.name;
}
