// System includes
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "StudentInfo.h"

// Using declarations
using std::string;
using std::vector;
using std::istream;

// Reads data for a student in StudentInfo struct from specified
// input stream
istream&
read(istream& in, StudentInfoT& si) {
    // Read student name, midterm and final grades
    in >> si.name >> si.midterm >> si.final;
    // Read homework grades
    readHw(in, si.homework);
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
