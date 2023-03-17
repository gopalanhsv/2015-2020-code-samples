#ifndef _GRADE_H_
#define _GRADE_H_

// System headers
#include <vector>
#include <string>

// Local includes

// Using declarations

// Typedefs, globals, statics

double grade(double, double, double);

double grade(double, double, const std::vector<double>&);

std::string numericToLetterGrade(double);

#endif /* _GRADE_H_ */
