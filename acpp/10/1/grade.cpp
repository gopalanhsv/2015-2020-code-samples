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

string
numericToLetterGrade(double grade) {
    // Range posts for numeric grades
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };

    // Corresponding names for letter grades
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };

    size_t n = sizeof(numbers) / sizeof(numbers[0]);

    // Iterate through the numeric grades looking for range post
    // which is not lesser than given grade. Return the letter
    // grade corresponding to same range post
    for (size_t i = 0; i != n; ++i) {
        if (grade >= numbers[i]) {
            return letters[i];
        }
    }
    return "\?\?\?";
}
