// Sytem headers
#include <vector>
#include <stdexcept>

// Local headers
#include "median.h"
#include "average.h"
#include "StudentInfo.h"
#include "grade.h"

// Using declarations
using std::vector;
using std::domain_error;

double
grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double
grade(double midterm, double final, const vector<double>& homework) {
    if (0 == homework.size()) {
        throw domain_error(
                "Error! Student has not done any homework! Exiting...!");
    }
    return grade(midterm, final, median(homework));
}

double
grade(const StudentInfoT& si) {
    return grade(si.midterm, si.final, si.homework);
}

bool
failGrade(const StudentInfoT& si) {
    return grade(si) < 60;
}
