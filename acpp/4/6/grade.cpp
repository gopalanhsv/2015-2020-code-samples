// Sytem headers

// Local headers
#include "median.h"
#include "StudentInfo.h"
#include "grade.h"

// Using declarations
using std::vector;

double
grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double
grade(const StudentInfoT& si) {
    return grade(si.midterm, si.final, si.homework);
}
