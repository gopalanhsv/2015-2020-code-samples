// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "median.h"
#include "grade.h"

// Using declarations
using std::vector;
using std::domain_error;

// Typedefs & globals


double
grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double
grade(double midterm, double final, const vector<double>& homework) {
    if (!homework.size()) {
        throw domain_error("Error! Student has done no homework! Exiting..!");
    }
    return grade(midterm, final, median(homework));
}
