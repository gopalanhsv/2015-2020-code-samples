// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "studentInfo.h"
#include "median.h"
#include "grade.h"

// Using declaration
using std::vector;
using std::domain_error;

double
grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double
grade(double midterm, double final, const vector<double>& hw) {
    if (0 == hw.size()) {
        throw
            domain_error("Error! Student has done any homework! Exiting...!");
    }

    return grade(midterm, final, median(hw));
}

double
grade(const StudentInfoT& si) {
    return grade(si.midterm, si.final, si.homework);
}
