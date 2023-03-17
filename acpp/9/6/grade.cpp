// System headers
#include <vector>
#include <string>
#include <stdexcept>

// Local includes
#include "median.h"
#include "grade.h"

// Using declarations
using std::vector;
using std::string;
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

bool
fgrade(double grade) {
    return grade < 60;
}

double
grade(double midterm, double final) {
    return 0.5 * midterm + 0.5 * final;
}

string
passFailGrade(double midterm, double final) {
    double g = grade(midterm, final);
    return fgrade(g) ? "F" : "P";
}
