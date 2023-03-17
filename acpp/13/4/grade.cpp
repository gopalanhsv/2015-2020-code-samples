// System headers
#include <vector>

// Local includes
#include "grade.h"
#include "median.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::string;

// Typedefs, globals, statics

double
grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double
grade(double midterm, double final, const std::vector<double>& homework) {
    if (0 == homework.size()) {
        throw
            domain_error("Error! Student has done no homework! Exiting..!");
    }

    return grade(midterm, final, median(homework));
}

string
numericToLetterGrade(double g) {
    // Range posts for numeric grades
    static const double numbers[] =
        { 97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };

    // Minimum letter grades corresponding to numbers
    static const char* const letters[] =
        { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };

    size_t n = sizeof(numbers) / sizeof(numbers[0]);

    for (size_t i = 0; i != n; ++i) {
        if (g >= numbers[i]) {
            return letters[i];
        }
    }

    return "\?\?\?";
}
