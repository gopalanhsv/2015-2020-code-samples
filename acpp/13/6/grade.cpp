// System headers
#include <vector>

// Local includes
#include "grade.h"
#include "median.h"

// Using declarations
using std::vector;
using std::domain_error;

// Typedefs, globals, statics

double
grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double
grade(double midterm, double final, const vector<double>& homework) {
    if (0 == homework.size()) {
        throw
            domain_error("Error! Student has done no homework! Exiting..!");
    }

    return grade(midterm, final, median(homework));
}

bool
passGrade(double grade) {
    return grade >= 60;
}
